#include "iostream"
#include "queue.hpp"

using namespace std;

int main() {

    queue f = createQueue(5);

    append(f, 1);
    append(f, 2);
    appendIni(f, 3);

    showQeue(f);

    system("pause");
    return 0;
}