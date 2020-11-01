#include <fdeep/fdeep.hpp>
int main()
{
    const auto model = fdeep::load_model("/Users/arnavgupta/Gram/Legato/tftest/models/fdeep_model.json");
    const auto result1 = model.predict(
        {fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(1)),
        std::vector<float>{1})});
    std::cout << fdeep::show_tensors(result1) << std::endl;
    const auto result2 = model.predict(
        {fdeep::tensor(fdeep::tensor_shape(static_cast<std::size_t>(1)),
        std::vector<float>{2})});
    std::cout << fdeep::show_tensors(result2) << std::endl;
}
