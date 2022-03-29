#include "iostream"
#include "queue.hpp"

using namespace std;

int main() {

    queue f = createQueue(5);

    append(f, 1);
    append(f, 2);

    cout << sumItems(f) << endl;

    system("pause");
    return 0;
}