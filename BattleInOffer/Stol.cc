
enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

///////////////////////////////////////////////////////////////////////
// Convert a string into an integer
///////////////////////////////////////////////////////////////////////
int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;

	if(str != NULL){
		const char* digit = str;
		// the first char in the string maybe '+' or '-'
		bool minus = false;
		if(*digit == '+')
			digit ++;
		else if(*digit == '-'){
			digit ++;
			minus = true;
		}
		
		// the remaining chars in the string
		while(*digit != '/0'){	
			if(*digit >= '0' && *digit <= '9'){
				num = num * 10 + (*digit - '0');
				// overflow  
				if(num > std::numeric_limits<int>::max()){
					num = 0;
					break;
				}
				digit ++;
			}
			// if the char is not a digit, invalid input
			else{
				num = 0;
				break;
			}
		}
		if(*digit == '/0'){
			g_nStatus = kValid;
			if(minus)
				num = 0 - num;
		}
	}
		
		return static_cast<int>(num);
}





