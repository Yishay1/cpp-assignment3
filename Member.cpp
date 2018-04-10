#include "Member.h"
int Member::cntr=0;
/*constructor*/
Member::Member(){
    id=++cntr;
}
/*add this member anothr member to following list
and add to another member this to followers list  */
void Member:: follow(Member &member)
{
	following[member.id]=&member;
	member.followers[id]=this;
}
/*remove the following from 2 lists */
void Member:: unfollow(Member &member)
{
	following.erase(member.id);
	member.followers.erase(this->id);
}
/*return how many following after this member*/
int Member::numFollowers()
{
	return followers.size();
}
/*return how many members this member following*/
int Member::numFollowing()
{
	return following.size();
}
/* return how many users in this social network*/
int Member::count()
{
	return cntr;
}
/*destructor- remove this member from all the lists of all the members*/
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
