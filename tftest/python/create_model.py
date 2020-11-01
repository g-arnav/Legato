import numpy as np
import sys

sys.path.append("/Users/arnavgupta/Gram/Legato/frugally-deep/keras_export")

from tensorflow.keras.layers import Input, Dense
from tensorflow.keras.models import Model
from convert_model import convert

inputs = Input(shape=(1,))
x = Dense(10, activation='relu')(inputs)
predictions = Dense(3, activation='softmax')(x)
model = Model(inputs=inputs, outputs=predictions)
model.compile(loss='categorical_crossentropy', optimizer='nadam')

model.fit(
    np.asarray([[1], [2]]),
    np.asarray([[1, 0, 0], [0, 0, 1]]), epochs=10000)

model.save('/Users/arnavgupta/Gram/Legato/tftest/models/keras_model.h5', include_optimizer=False)
convert('/Users/arnavgupta/Gram/Legato/tftest/models/keras_model.h5', "/Users/arnavgupta/Gram/Legato/tftest/models/fdeep_model.json", True)