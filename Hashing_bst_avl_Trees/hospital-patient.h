#ifndef _HOSPITAL_PATIENT_H
#define _HOSPITAL_PATIENT_H
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;
class record{
 private:
  char Patientid[8];
  char PatientName[20];
  char Address[30];
  char PhoneNo[11];
  char Disease[20];
  char DoctorName[20];
 public:
  record();
  int flag;
  void storeRecord(ifstream& );
  void storeRecord();
  void storeFile(ofstream& );
  void getId(char[] );
  char* getId();
  void Display();
  bool keyComparator(char[] );
};

record::record()
{
  flag=0;
}

void record::getId(char temp[])
{
  strcpy(temp,Patientid);
}

char* record::getId()
{
  return Patientid;
}

void record::storeRecord(ifstream& File)
{
  File>>Patientid>>PatientName>>Address>>PhoneNo>>Disease>>DoctorName;
  flag=1;
}

void record::storeRecord()
{
  cin>>Patientid>>PatientName>>Address>>PhoneNo>>Disease>>DoctorName;
  flag=1;
}

void record::storeFile(ofstream& outFile)
{
  outFile<<Patientid<<" "<<PatientName<<" "<<Address<<" "<<PhoneNo<<" "<<Disease<<" "<<DoctorName<<"\n";
}

bool record::keyComparator(char b[])
{
  if(strcmp(Patientid,b)==0)
   return true;
  return false;
}

void record::Display()
{
  cout<<"Patient Id "<< Patientid<<endl;
  cout<<"Patient Name "<<PatientName<<endl;
  cout<<"Address "<<Address<<endl;
  cout<<"PhoneNo "<<PhoneNo<<endl;
  cout<<"Disease "<<Disease<<endl;
  cout<<"DoctorName "<<DoctorName<<"\n"<<endl;
}

bool recordComp(record a, char b[])
{
  char temp1[8];
  a.getId(temp1);
  if(strcmp(temp1,b)==0)
    return true;
  else
    return false;
}

int recordComp(char a[], record b)
{
  char temp1[8];
  b.getId(temp1);
  if(strcmp(a,temp1)<0)
    return -1;
  else if(strcmp(a,temp1)==0)
    return 0;
  else
    return 1;
}

#endif
