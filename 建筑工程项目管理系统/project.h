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
const Building mark;  //全局变量，空标志记录
void Initial(const char *fileDat, int f);  //项目文件初始化
template<typename T>
void Change1(const char *fileDat, char *iname, long icode, int &flag);  //房屋建筑工程项目信息修改
template<typename T>
void Change2(const char *fileDat, char *iname, long icode, int &flag);  //市政工程项目信息修改
template<typename T>
void Delete(const char *fileDat, char *iname, long icode, int &flag);  //项目信息删除
Building** totalarray(int &num);  //总项目数组
townHouse** totalarray01(int &num);  //房屋建筑工程项目数组
publicWork** totalarray02(int &num);  //市政工程项目数组
civilBuilding** totalarray0(int &num);  //民用建筑项目数组
template<typename T>
void sort(T *building, int size);  //排序1
template<typename T>
void sort(T **building, int size);  //排序2
template<typename T>
void Readdat(const char *fileDat, T* &building, int &n);  //项目二进制文件读取
template<typename T>
int endMark(T building);  //重载函数，判断空标志记录（文件结束）
int endMark(Building *building);  //重载函数，判断空标志记录（文件结束）