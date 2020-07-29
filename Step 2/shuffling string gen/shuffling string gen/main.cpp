//#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "inc/DCT util.h"


class DCT_CUBING_shuffle_formula_gen
{//Dirac cpp tool: cubing.
public:
	std::vector<std::string>character;
	std::vector<std::string>postfix;
	std::string prefix_for_txt;
	//std::string postfix_for_txt;暂时不用
	std::string buffer;

private:
	std::vector<std::string> month_name;
	std::vector<std::string> day_name_in_week;

public:
	DCT_CUBING_shuffle_formula_gen()
	{
		character.push_back("L");
		character.push_back("R");
		character.push_back("F");
		character.push_back("B");
		character.push_back("U");
		character.push_back("D");
		postfix.push_back("");
		postfix.push_back("'");
		postfix.push_back("2");

		//
		struct tm newtime;
		__time64_t long_time;
		errno_t err;
		// Get time as 64-bit integer.
		_time64(&long_time);
		// Convert to local time.
		err = _localtime64_s(&newtime, &long_time);

		month_name.push_back("Jan");
		month_name.push_back("Feb");
		month_name.push_back("Mar");
		month_name.push_back("Apr");
		month_name.push_back("May");
		month_name.push_back("Jun");
		month_name.push_back("Jul");
		month_name.push_back("Aug");
		month_name.push_back("Sep");
		month_name.push_back("Oct");
		month_name.push_back("Nov");
		month_name.push_back("Dec");
		day_name_in_week.push_back("Sun");
		day_name_in_week.push_back("Mon");
		day_name_in_week.push_back("Tue");
		day_name_in_week.push_back("Wed");
		day_name_in_week.push_back("Thu");
		day_name_in_week.push_back("Fri");
		day_name_in_week.push_back("Sat");

		prefix_for_txt = std::string("Dirac's cubing tool - Shuffling formula gen 1.0\n\n")
			+ std::to_string(newtime.tm_year+1900)
			+"-"
			+ month_name[newtime.tm_mon]
			+ "-"
			+ std::to_string(newtime.tm_mday)
			+ " "
			+ std::to_string(newtime.tm_hour)
			+ ":"
			+ std::to_string(newtime.tm_min)
			+ ":"
			+ std::to_string(newtime.tm_sec)
			+ " ("
			+ month_name[newtime.tm_wday]
			+ ")\n\n"
			+ "Formula count: 3000\n"
			+ "Dirac Institute of Gameplay\n\n";
	};

	void gen()
	{
		buffer.clear();
		
		//srand
		srand(static_cast<unsigned int>(time(nullptr)));

		//pseudo global
		std::string this_formula;
		this_formula.reserve(31);
		int index;
		for (size_t n = 0; n < 3000; n++)
		{
			//生成一下番号  和  空行
			if (n % 10 == 0)
			{
				buffer += "\n" + std::to_string(n + 1) + ": \n\n";
			}
			else
			{
				if (n % 2 == 0)buffer += "\n";
			}
				
			//init
			bool avail_bools[6];
			for (size_t i = 0; i < 6; i++)
			{
				avail_bools[i] = true;
			}
			this_formula = "";


			for (size_t i = 0; i < 20; i++)//公式长度20
			{
				//断开，方便看。
				if (i % 10 == 0 && i > 0) this_formula += "  \t";

				std::vector<int> avail_indeces;
				avail_indeces.reserve(5);
				for (size_t i = 0; i < 6; i++)
				{
					if (avail_bools[i])avail_indeces.push_back(i);
				}
				index = avail_indeces[DCT_randomi(0, avail_indeces.size()-1)];

				switch (index)
				{
				case 0:
					avail_bools[0] = false;
					avail_bools[2] = true;
					avail_bools[3] = true;
					avail_bools[4] = true;
					avail_bools[5] = true;
					this_formula += character[0];
					break;
				case 1:
					avail_bools[1] = false;
					avail_bools[2] = true;
					avail_bools[3] = true;
					avail_bools[4] = true;
					avail_bools[5] = true;
					this_formula += character[1];
					break; 
				case 2:
					avail_bools[2] = false;
					avail_bools[0] = true;
					avail_bools[1] = true;
					avail_bools[4] = true;
					avail_bools[5] = true;
					this_formula += character[2];
					break;
				case 3:
					avail_bools[3] = false;
					avail_bools[0] = true;
					avail_bools[1] = true;
					avail_bools[4] = true;
					avail_bools[5] = true;
					this_formula += character[3];
					break;
				case 4:
					avail_bools[4] = false;
					avail_bools[0] = true;
					avail_bools[1] = true;
					avail_bools[2] = true;
					avail_bools[3] = true;
					this_formula += character[4];
					break;
				case 5:
					avail_bools[5] = false;
					avail_bools[0] = true;
					avail_bools[1] = true;
					avail_bools[2] = true;
					avail_bools[3] = true;
					this_formula += character[5];
					break;
				default:
					break;
				}
				this_formula += postfix[DCT_randomi(0, 2)];
				this_formula += " ";
			}
			// new line
			this_formula += "\n";

			buffer += this_formula;
		}//for 3000
	};

	void save_to_file(const char* filename)
	{
		
		std::ofstream output_file;
		output_file.open(filename);
		output_file << prefix_for_txt;
		output_file << buffer;
		output_file.close();
	};


public:
	void how_to_inside()
	{
		/*
		Step 1 ctor
		Step 2 gen
		Step 3 save to file

		example
		int main(int argc, char* argv[])
		{
			DCT_CUBING_shuffle_formula_gen fg;
			fg.gen();
			fg.save_to_file("Shuffling formula");

			return 0;
		}
		*/
	}
};




int main(int argc, char* argv[])
{
	DCT_CUBING_shuffle_formula_gen fg;
	fg.gen();
	fg.save_to_file("Shuffling formula.txt");

	return 0;
}


