#include <iostream>
using namespace std;

class CMPT135_String
{
private:
	char *buffer;	//A dynamic array to store the printable characters and a terminating null character
public:
	//static member function to compute the length of null terminated char arrays
	static int cstrlen(const char *cStr); 

	//Constructors
	CMPT135_String();
	CMPT135_String(const char &c);
	CMPT135_String(const char *cStr); //*cStr is a null terminated char array
	CMPT135_String(const CMPT135_String &s);

	//Destructor
	~CMPT135_String();

	//Assignment operators
	CMPT135_String& operator = (const CMPT135_String &s);
	CMPT135_String& operator = (const char &c);
	CMPT135_String& operator = (const char *cStr); //*cStr is a null terminated char array

	//Getter member functions
	int getLength() const;
	char& operator[](const int &index) const;

	//Setter member functions
	void append(const char &c);
	void append(const CMPT135_String &s);
	void append(const char *cStr); //*cStr is a null terminated char array

	//Other member functions
	int findCharIndex(const char &c) const;
	int reverseFindCharIndex(const char &c) const;
	int countChar(const char &c) const;
	CMPT135_String getSubString(const int &startIndex, const int &len) const;
	bool isSubString(const CMPT135_String &s) const;
	bool isSubString(const char *cStr) const; //*cStr is a null terminated char array
	void reverse();
	void removeChar(const char &c);
	void replaceChar(const char &c1, const char &c2);

	//Operator member functions
	CMPT135_String operator + (const char &c) const;
	CMPT135_String operator + (const CMPT135_String &s) const;
	CMPT135_String operator + (const char *cStr) const; //*cStr is a null terminated char array
	CMPT135_String& operator += (const char &c);
	CMPT135_String& operator += (const CMPT135_String &s);
	CMPT135_String& operator += (const char *cStr); //*cStr is a null terminated char array
	bool operator == (const CMPT135_String &s) const;
	bool operator == (const char *cStr) const; //*cStr is a null terminated char array
	bool operator != (const CMPT135_String &s) const;
	bool operator != (const char *cStr) const; //*cStr is a null terminated char array
	bool operator < (const CMPT135_String &s) const;
	bool operator < (const char *cStr) const; //*cStr is a null terminated char array
	bool operator > (const CMPT135_String &s) const;
	bool operator > (const char *cStr) const; //*cStr is a null terminated char array
	bool operator <= (const CMPT135_String &s) const;
	bool operator <= (const char *cStr) const; //*cStr is a null terminated char array
	bool operator >= (const CMPT135_String &s) const;
	bool operator >= (const char *cStr) const; //*cStr is a null terminated char array

	//Friend Functions (for operators)
	friend CMPT135_String operator + (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend CMPT135_String operator + (const char &c, const CMPT135_String &s);
	friend bool operator == (const char *cStr, const CMPT135_String &s); //*cStr a null terminated char array
	friend bool operator != (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator < (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator > (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator <= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend bool operator >= (const char *cStr, const CMPT135_String &s); //*cStr is a null terminated char array
	friend ostream& operator << (ostream &outputStream, const CMPT135_String &s);
	friend istream& operator >> (istream &inputStream, CMPT135_String &s);
};

int CMPT135_String::cstrlen(const char *cStr)
{
	if(cStr == nullptr)
		return 0;
	else
	{
		int len =0;
		while(cStr[len] !='\0')
			len++;
		return len;
	}
}
CMPT135_String::CMPT135_String()
{
	buffer= nullptr;
}
CMPT135_String::CMPT135_String(const char &c)
{
	buffer = new char[2];
	buffer[0] =c;
	buffer[1]='\0';
}
CMPT135_String::CMPT135_String(const char *cStr)
{
	if(cStr == nullptr)
		buffer = nullptr;
	else
	{
		buffer = new char[CMPT135_String::cstrlen(cStr)+1];
		int i=0;
		for(i; cStr[i] !=0; i++)
		{
			buffer[i] = cStr[i];
		}
		buffer[i] = '\0';
	}
}
CMPT135_String::CMPT135_String(const CMPT135_String &s)
{
	int length=cstrlen(s.buffer);
	if(length>0)
	{
		buffer=new char[length+1];
		for(int x=0;x<length;x++)
			buffer[x]=s.buffer[x];
		buffer[length]='\0';
	}
	else
	{
		buffer=nullptr;
	}
}
CMPT135_String::~CMPT135_String()
{
	if(buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}
CMPT135_String& CMPT135_String::operator = (const CMPT135_String &s)
{
	int l=cstrlen(s.buffer);
	this->buffer= new char[l+1];
	for(int i=0;i<l;i++)
		this->buffer[i]=s.buffer[i];
	this->buffer[l]='\0';
	return *this;
}
CMPT135_String& CMPT135_String::operator = (const char &c)
{
	if(this->cstrlen(buffer)>0)
		this->~CMPT135_String();
	buffer = new char[2];
	buffer[0] = c;
	buffer[1]= '\0';
	return *this;
}
CMPT135_String& CMPT135_String::operator = (const char *cStr)
{
	if(this->cstrlen(buffer)>0)
		this->~CMPT135_String();
	buffer = new char[CMPT135_String::cstrlen(cStr)];
	int i=0;
	for(i; cStr[i]!='\0';i++)
	{
		buffer[i] = cStr[i];
	}
	buffer[i] = '\0';
	return *this;
}
int CMPT135_String::getLength() const
{
	return CMPT135_String::cstrlen(buffer);
}
char& CMPT135_String::operator[](const int &index) const
{
	if(index<0 || index> this->getLength()-1)
	{
		cout<<"Error, Index is out of bounds"<<endl;
		abort();
	}
	return this->buffer[index];
}
void CMPT135_String::append(const char &c)
{
	char *temp = new char[this->getLength()+2];
	int i=0;
	for(i; i<this->getLength(); i++)
	{
		temp[i] = this->buffer[i];
	}
	temp[i] = c;
	temp[i+1]= '\0';
	if(this->getLength()>0)
		this->~CMPT135_String();
	this->buffer = temp;
}
void CMPT135_String::append(const CMPT135_String &s)
{
	int size = this->getLength()+s.getLength()+1;
	char *temp= new char[size];
	int i=0;
	for(i; i< this->getLength(); i++)
	{
		temp[i] = this->buffer[i];
	}
	for(i; i< s.getLength(); i++)
		temp[i] = s.buffer[i];
	temp[i] = '\0';
	if(this->getLength()>0)
		this->~CMPT135_String();
	this->buffer = temp;
}
void CMPT135_String::append(const char *cStr)
{
	int size = this->getLength()+ CMPT135_String::cstrlen(cStr)+1;
	char *temp = new char[size];
	int i=0;
	for(i; i<this->getLength(); i++)
		temp[i] = this->buffer[i];
	for(i; i<CMPT135_String::cstrlen(cStr); i++)
		temp[i] = cStr[i];
	temp[i] = '\0';
	if(this->getLength()>0)
		this->~CMPT135_String();
	this->buffer = temp;

}
int CMPT135_String::findCharIndex(const char &c) const
{
	for(int i=0; i<this->getLength(); i++)
	{
		if(this->buffer[i] == c)
			return i;
	}
	return -1;
}
int CMPT135_String::reverseFindCharIndex(const char &c) const
{
	for(int i=this->getLength()-1; i>=0; i--)
	{
		if(buffer[i] == c)
			return i;
	}
	return -1;
}
int CMPT135_String::countChar(const char &c) const
{
	int count =0;
	for(int i=0; i<this->getLength();i++)
	{
		if(this->buffer[i] == c)
			count++;
		else
			continue;
	}
	return count;
}
CMPT135_String CMPT135_String::getSubString(const int &startIndex, const int &len) const
{
	CMPT135_String s;
	int j =0;
	if(startIndex<0 || startIndex>this->getLength()-1)
		return s;
	else if(startIndex+len>this->getLength())
	{
		for(int i= startIndex; i<this->getLength();i++)
		{
			s.buffer[j] = this->buffer[i];
			j++;
		}
		return s;
	}
	else
	{
		for(int i = startIndex; i<startIndex +len; i++)
		{
			s.buffer[j] = this->buffer[i];
			j++;
		}
		return s;
	}
}
bool CMPT135_String::isSubString(const CMPT135_String &s) const
{
	int length=s.getLength();
	bool state=false;
	for(int i=0;i<=(length-this->getLength());i++)
	{
		int j;
		for(j=0;j<this->getLength();j++)
		{
			if(s.buffer[i+j]!=buffer[j])
				break;
		}
		if(j==this->getLength())
			state=true;
	}
	return state;
}
bool CMPT135_String::isSubString(const char *cStr) const
{
	int length=cstrlen(cStr);
	bool state= false;
	for(int i=0;i<=(length-this->getLength());i++)
	{
		int j;
		for(j=0;j<this->getLength();j++)
		{
			if(cStr[i+j]!=buffer[j])
				break;
		}
		if(j==this->getLength())
			state=true;
	}
	return state;
}
void CMPT135_String::reverse()
{
	for(int i=this->getLength()-1; i>=0; i--)
	{
		cout<<this->buffer[i];
	}
}
void CMPT135_String::removeChar(const char &c)
{
	int count=0;
	for(int i=0;i<this->getLength();i++)
	{
		if(this->buffer[i]==c)
			count++;
	}
	if(count==this->getLength())
	{
		char *temp=new char[0];
		this->buffer= temp;
	}
	else
	{
		int length=this->getLength();
		for(int j=0;j<length;j++)
		{
			if(buffer[j]==c)
			{
				for(int k=j;k<=length;k++)
					{
						buffer[k]=buffer[k+1];
					}
			}
		}
	}
}
void CMPT135_String::replaceChar(const char &c1, const char &c2)
{
	int length=this->getLength();
	for(int i=0;i<length;i++)
	{
		if(buffer[i]==c1)
			buffer[i]=c2;
	}
}
CMPT135_String CMPT135_String::operator + (const char &c) const
{
	int length=cstrlen(this->buffer);
	char *temp=new char[length+1];
	for(int i=0;i<length;i++)
		temp[i]=buffer[i];
	for(int j=length;j<length+1;j++)
		temp[j]=c;
	temp[length+1]='\0';
	return CMPT135_String(temp);
}
CMPT135_String CMPT135_String::operator + (const CMPT135_String &s) const
{
	int l1=cstrlen(this->buffer);
	int l2=s.getLength();
	char *temp=new char [l1+l2+1];
	for(int i=0; i<l1;i++)
		temp[i]=buffer[i];
	for(int j=l1,k=0; j<l1+l2; j++,k++)
		temp[j]=s.buffer[k];
	temp[l1+l2]='\0';
	return CMPT135_String(temp);
}
CMPT135_String CMPT135_String::operator + (const char *cStr) const
{
	int l1=cstrlen(this->buffer);
	int l2=cstrlen(cStr);
	char *temp= new char[l1+l2+1];
	for(int i=0;i<l1;i++)
		temp[i]=buffer[i];
	for(int j= l1,k=0;j<l1+l2;j++,k++)
		temp[j]=cStr[k];
	temp[l1+l2]='\0';
	return CMPT135_String(temp);
}
CMPT135_String& CMPT135_String::operator += (const char &c)
{
	this->append(c);
	return *this;
}
CMPT135_String& CMPT135_String::operator += (const CMPT135_String &s)
{
	this->append(s);
	return *this;
}
CMPT135_String& CMPT135_String::operator += (const char *cStr)
{
	this->append(cStr);
	return *this;
}
bool CMPT135_String::operator == (const CMPT135_String &s) const
{
	int counter =0;
	if(this->getLength()!= s.getLength())
		return false;
	else
	{
		for(int i=0; i<this->getLength(); i++)
		{
			if(this->buffer[i] == s.buffer[i])
				counter++;
		}
		if(counter == this->getLength())
			return true;
		else
			return false;
	}
}
bool CMPT135_String::operator == (const char *cStr) const
{
	int counter =0;
	if(this->getLength()!= CMPT135_String::cstrlen(cStr))
		return false;
	else
	{
		for(int i=0; i<this->getLength(); i++)
		{
			if(this->buffer[i] == cStr[i])
				counter++;
		}
		if(counter == this->getLength())
			return true;
		else
			return false;
	}
}
bool CMPT135_String::operator != (const CMPT135_String &s) const
{
	int counter =0;
	if(this->getLength()!= s.getLength())
		return true;
	else
	{
		for(int i=0; i<this->getLength(); i++)
		{
			if(this->buffer[i] == s.buffer[i])
				counter++;
		}
		if(counter == this->getLength())
			return false;
		else
			return true;
	}
}
bool CMPT135_String::operator != (const char *cStr) const
{
	int counter =0;
	if(this->getLength()!= CMPT135_String::cstrlen(cStr))
		return true;
	else
	{
		for(int i=0; i<this->getLength(); i++)
		{
			if(this->buffer[i] == cStr[i])
				counter++;
		}
		if(counter == this->getLength())
			return false;
		else
			return true;
	}
}
bool CMPT135_String::operator < (const CMPT135_String &s) const
{
	int length=s.getLength();
	if(this->getLength()!= length)
		return false;

	else
	{
		for (int i=0;i<length;i++)
		{
			if(buffer[i]>=s.buffer[i])
				return false;
		}
		return true;
	}
}
bool CMPT135_String::operator < (const char *cStr) const
{
	int length=this->getLength();
	if(length!=cstrlen(cStr))
		return false;
	else
	{
		for(int i=0; i<length;i++)
		{
			if(buffer[i]>=cStr[i])
				return false;
		}
		return true;
	}
}
bool CMPT135_String::operator > (const CMPT135_String &s) const
{
	if(*this==s)
		return false;
	else
		return !(*this<s);
}
bool CMPT135_String::operator > (const char *cStr) const
{
	if(*this==cStr)
		return false;
	else
		return !(*this<cStr);
}
bool CMPT135_String::operator <= (const CMPT135_String &s) const
{
	return (*this<s || *this==s);
}
bool CMPT135_String::operator <= (const char *cStr) const
{
	return (*this<cStr || *this==cStr);;
}
bool CMPT135_String::operator >= (const CMPT135_String &s) const
{
	return ( *this>s || *this==s);
}
bool CMPT135_String::operator >= (const char *cStr) const
{
	return ( *this>cStr || *this==cStr);
}
CMPT135_String operator + (const char *cStr, const CMPT135_String &s)
{
	int l1=CMPT135_String::cstrlen(cStr);
	int l2=s.getLength();
	char *temp=new char[l1+l2+1];
	for(int i=0;i<l1;i++)
		temp[i]=cStr[i];
	for(int j=l1,k=0;j<l1+l2;j++,k++)
		temp[j]=s.buffer[k];
	temp[l1+l2]='\0';
	return CMPT135_String(temp);
}
CMPT135_String operator + (const char &c, const CMPT135_String &s)
{
	int length=s.getLength();
	char *temp= new char [length+1];
	temp[0]=c;
	for(int i=1,j=0;i<length+1;i++,j++)
		temp[i]=s.buffer[j];
	temp[length+1]='\0';
	return CMPT135_String(temp);
}
bool operator == (const char *cStr, const CMPT135_String &s)
{
	int l1=CMPT135_String::cstrlen(cStr);
	int l2=s.getLength();
	if(l1!=l2)
		return false;
	else
	{
		for(int i=0;i<l1;i++)
		{
			if(cStr[i]!=s.buffer[i])
				return false;
		}
		return true;
	}
}
bool operator != (const char *cStr, const CMPT135_String &s)
{
	return !(cStr==s);
}
bool operator < (const char *cStr, const CMPT135_String &s)
{
	int l1=s.getLength();
	int l2=CMPT135_String::cstrlen(cStr);
	if(l1!=l2)
		return false;
	else
	{
		for(int i=0;i<l2;i++)
		{
			if(s[i]>=cStr[i])
				return false;
		}
		return true;
	}
}
bool operator > (const char *cStr, const CMPT135_String &s)
{
	if(cStr==s)
		return false;
	else
		return !(cStr < s);
}
bool operator <= (const char *cStr, const CMPT135_String &s)
{
	return (cStr<s || cStr==s);
}
bool operator >= (const char *cStr, const CMPT135_String &s)
{
	return (!(cStr<s) || cStr==s);
}
ostream& operator << (ostream &outputStream, const CMPT135_String &s)
{
	for (int i = 0; i < s.getLength(); i++)
		outputStream << s.buffer[i];
	return outputStream;
}
istream& operator >> (istream &inputStream, CMPT135_String &s)
{
	s.~CMPT135_String();
	char c;
	while (true)
	{
		inputStream.get(c);
		if (c == '\n')
			break;
		else
			s.append(c);
	}
	return inputStream;
}

int main()
{
	//Test the cstrlen static member function'
	cout << "The length of \"Yonas\" is " << CMPT135_String::cstrlen("Yonas") << endl;
	cout << "The length of \"\" is " << CMPT135_String::cstrlen("") << endl;
	cout << "The length of nullptr is " << CMPT135_String::cstrlen(nullptr) << endl;

	//Test default constructor and getLength member functions
	CMPT135_String s1;
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	//Test non-default constructor and getLength member functions
	CMPT135_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.getLength() << endl;

	//Test non-default constructor and getLength member functions
	CMPT135_String s3 = "CMPT 135";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test copy constructor and getLength member functions
	CMPT135_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;
	
	//Test destructor and getLength member functions
	s4.~CMPT135_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test assignment operator and getLength member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test indexing operator
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'a';
	cout << "s4[2] is " << s4[2] << endl;
	s4[3] = 't';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.getLength() << endl;

	//Test append function and getLength member functions
	s1.append(s4);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;

	//Test append function and getLength member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test append function and getLength member functions
	s3.append("201901");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.getLength() << endl;

	//Test findCharIndex function
	char ch = '1';
	int k = s3.findCharIndex(ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.findCharIndex('m');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test reverseFindCharIndex function
	ch = '1';
	k = s3.reverseFindCharIndex(ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = s3.reverseFindCharIndex('m');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	
	//Test getSubString function
	s1 = s3.getSubString(10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1 = s3.getSubString(10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	
	//Test isSubString function
	if (s1.isSubString(s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902029010190";
	if (s1.isSubString(s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902019010190";
	if (s1.isSubString(x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;
	
	//Test reverse function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	s1.reverse();
	cout << "After reversing it, s1 is \"" << s1 << "\" and its length is " << s1.getLength() << endl;
	
	//Test countChar function
	ch = '1';
	k = s1.countChar(ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	//Test removeChar function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	s1.removeChar(ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	s3.removeChar(ch);
	cout << "\"" << s3 << "\"" << endl;
	
	//Test replaceChar function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	s2.replaceChar('1', '5');
	cout << s2 << endl;

	//Test + operator
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	//Test += operatror
	s2 = "Test";
	cout << "s1 is \"" << s1 <<"\", s2 is \"" << s2 << "\", and s3 is \"" << s3 << "\"" << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl; 
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	//Test relational operators
	s1 = "Test1";
	s2 = "";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	//Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	//Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" < s1 is " << ("Test2" < s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" >= s1 is " << ("Test2" >= s1) << endl;

	//Test input streaming operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;

	system("pause");
	return 0;
}