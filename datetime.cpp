/*#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //作业：将当前公历转换为农历显示出来 
};
class MoonTime{
private:
	int year_ ,month_ ,day_;
	int hour_, minute_, second_;
public:
	MoonTime();
	~MoonTime();
	void showTime();
  void showMoon();
}; 
int main() {
  DateTime dt, dt1;
  std::cout << &dt << std::endl;
  std::cout << &dt1 << std::endl;
  dt.showTime();
  dt1.showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  
}
MoonTime::MoonTime()
{
	year_ = 2020; month_ = 2; day_ = 37;
  hour_ = 11; minute_ = 27; second_ = 55;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  
}
void MoonTime::showMoon()
{
	printf("当前时间：%d/%d/%d/ %d:%d:%d\n",year_, month_,day_, hour_, minute_,second_);
}*/
#include <stdio.h>
int Change(int year,int month,int day);
int main()
{
	int year, month, day;
	printf("请输入公历，如“2020年1月1日”：");
	scanf("%d%d%d",&year,&month,&day);
	printf("%d年%d月%d日",year,month,day);
	Change(year,month,day);
}
int Change(int year, int month, int day)
{
	int i;
	int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int date=0;//计算和70年元旦的数量差 
	int yeardate[51];
	for(i=0;i<51;i++){
		yeardate[i]=365;
		if (((1970+i) %4==0 && (1970+i)%100 !=0 )||(1970+i)%400==0){
			yeardate[i]=366;
	} 
	}
	if ((year %4==0 && year%100 !=0 )||year%400==0){
		monthday[1]=29;
	} 
	char moonyear1[10][4]={"甲","乙","丙","丁","戊","己","庚","辛","壬","癸"};
	char moonyear2[12][4]={"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥"};
	int moonmonth, moonday;
	int moonyear1num,moonyear2num;
	for(i=0;i<(year-1970);i++){
		date=date+yeardate[i];
	}
	for(i=0;i<(month-1);i++){
		date=date+monthday[i];
	}
	date=date+day-1;
	if(year==1970 && month==1 && day==1){
		moonyear1num=5;
		moonyear2num=9;
		moonmonth=11;
		moonday=24;
		
	}
	//先假设农历每月30天而且没有闰月
	for(i=0;i<date;i++){
		moonday=moonday+1;
		if(moonday==31){
			moonday=1;
			moonmonth=moonmonth+1;
		}
		if(moonmonth==13){
			moonmonth=1;
			moonyear1num=moonyear1num+1;
			moonyear2num=moonyear2num+1;
		}
		if(moonyear1num==10){
			moonyear1num=0;
		}
		if(moonyear2num==12){
			moonyear2num=0;
		}
	} 
	printf("农历%s%s年%d月%d日",moonyear1[moonyear1num],moonyear2[moonyear2num],moonmonth,moonday);
	return 0;
	
		
		
	}
























 
 
