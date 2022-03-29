#include "iostream"
#include "queue.hpp"

using namespace std;

int main() {

    queue f = createQueue(3);

    append(f, 2);
    append(f, 3);
    append(f, 4);

    showQeue(f);

    removeItem(f);
    append(f, 5);

    showQeue(f);

    removeItem(f);
    removeItem(f);

    showQeue(f);

    append(f, 1);
    append(f, 1);

    showQeue(f);

    removeItem(f);

    showQeue(f);

    system("pause");
    return 0;
}