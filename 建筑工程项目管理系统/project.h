#pragma once
#include<fstream>
#include<iostream>
#include<cstring>
#include<time.h>
#include"Date.h"
#include"building.h"
#include"townHouse.h"
#include"publicWork.h"
#include"civilBuilding.h"
#include"indusBuilding.h"
#include"Resident.h"
#include"Office.h"
#include"Service.h"
#include"Structure.h"
#include"Traffic.h"
#include"Plant.h"
#include"Sign.h"
const Building mark;  //ȫ�ֱ������ձ�־��¼
void Initial(const char *fileDat, int f);  //��Ŀ�ļ���ʼ��
template<typename T>
void Change1(const char *fileDat, char *iname, long icode, int &flag);  //���ݽ���������Ŀ��Ϣ�޸�
template<typename T>
void Change2(const char *fileDat, char *iname, long icode, int &flag);  //����������Ŀ��Ϣ�޸�
template<typename T>
void Delete(const char *fileDat, char *iname, long icode, int &flag);  //��Ŀ��Ϣɾ��
Building** totalarray(int &num);  //����Ŀ����
townHouse** totalarray01(int &num);  //���ݽ���������Ŀ����
publicWork** totalarray02(int &num);  //����������Ŀ����
civilBuilding** totalarray0(int &num);  //���ý�����Ŀ����
template<typename T>
void sort(T *building, int size);  //����1
template<typename T>
void sort(T **building, int size);  //����2
template<typename T>
void Readdat(const char *fileDat, T* &building, int &n);  //��Ŀ�������ļ���ȡ
template<typename T>
int endMark(T building);  //���غ������жϿձ�־��¼���ļ�������
int endMark(Building *building);  //���غ������жϿձ�־��¼���ļ�������