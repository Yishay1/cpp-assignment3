#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<map>
using namespace std;
/*this class represents a member in a social network*/
class Member
{
private:
    map<int,Member*> followers;
    map<int,Member*> following;
public:
	int id;
	static int cntr;
	Member();
	~Member();
	int numFollowers();
	int numFollowing();
	static int count();
	void follow(Member &m);
	void unfollow(Member &m);
};
#endif
