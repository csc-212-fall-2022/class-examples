#include <functional>
#include <vector>

namespace chapter8 {

auto CountingSort(const std::vector<int> &A, const int &k) -> std::vector<int>;

auto CountingSort(const std::vector<int> &A, const int &k, std::function<int(int)> func) -> std::vector<int>;
}