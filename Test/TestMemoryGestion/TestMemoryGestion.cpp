#include <vector>
#include <vld.h>
#include "Utilities/MemoryGestion/StaticMemoryAllocator.hpp"
#include "Utilities/MemoryGestion/PoolAllocator.hpp"

class TElement
{
private:
	char t_array[100];

public :
	TElement()
	{
		t_array[0] = 1;
	}

	~TElement()
	{
		
	}

	int getNumber()
	{
		return t_array[0];
	}
};

class TDependance
{
private:
	std::vector <int> t_array;

public:
};

int main()
{
	std::cout << "--------- STATIC MEMORY ALLOCATOR ----------------" << std::endl;

	StaticMemoryAllocator stack;

	std::vector <TElement*> v_TElement(10, NULL);

	stack.init(1000);

	for (int i = 0; i < 10; i++)
	{
		v_TElement[i] = (TElement*)stack.allocate(100);
		{
			*v_TElement[i] = TElement();
		}
	}
	
	std::cout << "Expected result : 1" << std::endl;
	std::cout << "Result obtained : " << v_TElement[3]->getNumber() << std::endl;

	//stack.clear();

	std::cout << "------------ POOL ALLOCATOR -------------------------" << std::endl;
	PoolAllocator<long> pool;
	std::vector <long*> v_long(100, NULL);

	pool.init(100);
	
	for (unsigned int i = 0; i < 100; i++)
	{
		v_long[i] = pool.getFreeElement();
		{
			*v_long[i] = (long)i;
		}
	}

	for (unsigned int i = 0; i < 100; i++)
	{
		std::cout << *v_long[i] << std::endl;
	}

	pool.removeElement(20);

	pool.removeElement(30);

	pool.removeElement(1);

	long* test = pool.getFreeElement();
	*test = 10;

	std::cout << "Expected result : 10" << std::endl;
	std::cout << "Result obtained : " << *test << std::endl;

	return 0;
}
