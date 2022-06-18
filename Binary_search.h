#pragma once

int binary_search(int arch[], int search)
{
	int i = 0;
	int max = sizeof(arch) / sizeof(arch[0]);
	int min = 0;
	while (arch[i] != search || arch[min] != search || arch[max] != search)
	{
		if (search > arch[max])
		{
			return 0;
		}
		if (search > arch[i])
		{
			min = arch[i];
			i = middle_min(max, min);
		}
		if (search < arch[i])
		{
			max = arch[i];
			i = middle_max(max, min);
		}
		if (search == arch[i])
		{
			return i;
		}
		if (search == arch[max])
		{
			return max;
		}
		if (search == arch[min])
		{
			return min;
		}
	}

}


int delta(int max, int min)
{
	return max - min;
}

int middle_max(int max, int min)
{
	int b = delta(max, min);
	b = b / 2;
	return b;
}

int middle_min(int max, int min)
{
	int b = delta(max, min);
	b = b / 2;
	return b + min;
}


int search_num(int search, int max, int min)
{
	int a = 0;
	std::cout << "max = " << max << std::endl;
	std::cout << "min = " << min << std::endl;
	while (search != a || search != min || search != max)
	{
		if (search > max)
		{
			return 0;
		}
		if (search > a)
		{
			min = a;
			std::cout << "new min: " << min << std::endl;
			a = middle_min(max, min);
			std::cout << "new a: " << a << std::endl;
		}
		if (search < a)
		{
			max = a;
			std::cout << "new max: " << max << std::endl;
			a = middle_max(max, min);
			std::cout << "new a: " << a << std::endl;
		}
		if (search == a)
		{
			return a;
		}
		if (search == max)
		{
			return max;
		}
		if (search == min)
		{
			return min;
		}
	}
}