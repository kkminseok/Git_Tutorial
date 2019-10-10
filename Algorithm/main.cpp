#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
#include<math.h>



int main()
{
	int T;
	std::cin >> T;
	std::cin.ignore(1000,'\n');
	for (int i = 0; i < T; ++i)
	{
		
		double result = 0;
		std::stack<char> st1;
		std::string str;
		std::getline(std::cin, str);
		
		
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == 'n')
			{
				st1.push('n');
			}
			else if (str[j] == 'w')
				st1.push('w');
		}
		
		int count = 0;
		if (st1.size() == 1)
		{
			st1.top() == 'n' ? std::cout <<"#"<<i+1<<" "<< 0 << std::endl : std::cout <<"#"<<i+1<<" "<< 90 << std::endl;
			continue;
		}
		int beforen;
		int befored;
		int result2 = 0;
		while (st1.empty() == 0)
		{
			int numerator = 90;// 분자
			int denominator = (int)pow(2, count);
	
			if (count == 0 && st1.top() == 'n')
			{
				beforen = 0;
				befored = 1;
				++count;
				st1.pop();
				continue;
			}
			else if (count == 0 && st1.top() == 'w')
			{
				beforen = 90;
				befored = 1;
				++count;
				st1.pop();
				continue;
			}
			if (st1.top() == 'n')
			{
				
				//기약분수로 바꿈
				while (numerator % 2 == 0 && denominator % 2 == 0)
				{
					numerator /= 2;
					denominator /= 2;
				}
				while (befored != denominator)
				{
					befored *= 2;
					beforen *= 2;
				}
				result2 = beforen - numerator;
				befored = denominator;
				beforen = result2;
			
			}
			else if (st1.top() == 'w')
			{
				//기약분수로 바꿈
				if (numerator % 2 == 0 && denominator % 2 == 0)
				{
					numerator /= 2;
					denominator /= 2;
				}
				while (befored != denominator)
				{
					befored *= 2;
					beforen *= 2;
				}
				result2 = beforen + numerator;
				befored = denominator;
				beforen = result2;
				
			}
			
			st1.pop();
			++count;
	
		}
		if (befored != 1)
			std::cout <<"#"<<i+1<<" "<< result2 << "/" << befored << std::endl;
		else
			std::cout << "#" << i + 1 << " " << result2 << std::endl;
		
	}

	return 0;
}
