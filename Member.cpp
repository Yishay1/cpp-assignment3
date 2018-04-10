#include "Member.h"
int Member::cntr=0;

Member::Member(){
    id=++cntr;
}

void Member:: follow(Member &member)
{
	following[member.id]=&member;
	member.followers[id]=this;
}

void Member:: unfollow(Member &member)
{
	following.erase(member.id);
	member.followers.erase(this->id);
}

int Member::numFollowers()
{
	return followers.size();
}

int Member::numFollowing()
{
	return following.size();
}

int Member::count()
{
	return cntr;
}

Member::~Member()
{
	map <int, Member*> :: iterator i;
	for(i=following.begin(); i!=following.end();i++)
	{
		i->second->followers.erase(this->id);
	}
	
	for(i=followers.begin();i!=followers.end();i++)
	{
		i->second->following.erase(this->id);
	}
	cntr--;
}
