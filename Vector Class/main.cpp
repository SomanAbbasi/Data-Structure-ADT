#include "Vector.h"

int main()
{
    try
    {
        Vector<int> v1 = {1, 2};

        v1.push_back(20);
        v1.push_back(10);

        v1.display();

        v1.sortVector();
        v1.display();

        cout << "Min: " << v1.minElement() << endl;
        cout << "Max: " << v1.maxElement() << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
