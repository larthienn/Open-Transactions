/************************************************************
 * 
 *  OTNewcli  -- Open Transactions new command line interface
 * 
 * 	Written in 2013 by rfree (rfree@gmx.us) and other members of 
 * 	open-source community
 * 
 * 	To the extent possible under law, the author(s) have dedicated all 
 * 	copyright and related and neighboring rights to this software to 
 * 	the public domain worldwide. This software is distributed without 
 * 	any warranty. 
 * 
 * 	You should have received a copy of the CC0 legalcode along with this
 * 	work. If not, see: 
 * 	http://creativecommons.org/publicdomain/zero/1.0/
 * 
 * 	OTNewcli is developed as a part of OPEN TRANSACTIONS project
 * 
 * 	Where applicable (under given jurisdiction's law system), 
 * 	we want to give away our code as CC0 (Creative Commons 0) 
 * 	as detailed below, however, some parts of code might be not fully 
 * 	ours to licence/decide (from point of view of given law system), 
 * 	because they are connecting to other work. In such cases, 
 * 	the general Open Transaction licence as published by 
 * 	FellowTraveller on GitHub should be applied if possible (because 
 * 	it clarifies how to deal with linking to work like Lucre code, 
 * 	OpenSSL code, and so on). 
 * 
 * 	We also allow this code to be released to Public Domain, but again, 
 * 	we do not verify how is that possible in given law system. We take 
 * 	absolutely no legal responsibility about licensing this code (nor 
 * 	patent nor copyright nor any other law related issues). We are not 
 * 	lawyers, and it is up to You to find out what laws apply for your 
 * 	case. Do not use any of this code if you don't agree.
 *
 * 	PROJECT GIT REPOSITORY:
 * 	https://github.com/rfree/Open-Transactions/
 * 
 ***********************************************************************
 * 	OPEN TRANSACTION RELATED INFORMATIONS:
 *********************************************************************** 
 *                    OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 * 
 * 	BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  OFFICIAL OPEN TRANSACTIONS PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 
 **************************************************************/
/**

OT Hints (new CLI - new commandline : auto complete commands, verify, check, etc)

Goal: this project aims to provide auto completion of newCLI OT commands, see [Description_of_auto_completion]

This subproject is separated out of OT, and uses C++11 and few other modern coding style changes.

Rules of language: use C++11, do not use boost (thougl we could copy small part of boost source code if needed,
or headers-only library)

Currently this is developed rapidly as 1 big file, to be splited soon, composed of this parts:
- nExamplesOfConvention - documenation of coding style convention
- nOT::nUtil - various utils for modern (C++11) OT ; ToStr(), OT_CODE_STAMP
- nOT::nNewcli - new command line classes, to parse the command line options, and to execute commands
- nOT::nOTHint - new command line auto-completion. Move here things usable only for auto-completion and nothing else
- nOT::nTests - the testcases for our code
- main() is here

Coding rules:
- testcase driven development
- testcase on almost each compilation, commit often
- secure - use asserts, secure methods, etc. Use static analysis
- fast - optimize for speed overall, and in picked bottlenecks
- scalable - assume usage in massive scripts one day, e.g. 1 million users email server :)
- document all conventions, all code; Entire WG (working group) must know all of them
- flexible - easy to tune, to extend, in object-oriented way

File format of sources: identation with \t char, which we assume is 2 spaces wide. Unicode, UTF-8.

*/

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>
#include <stdexcept>

// OTNewcliCmdline

// list of thigs from libraries that we pull into namespace nOT::nNewcli
// we might still need to copy/paste it in few places to make IDEs pick it up correctly
#define OT_COMMON_USING_NAMESPACE \
using std::string; \
using std::vector; \
using std::list; \
using std::set; \
using std::map; \
using std::unique_ptr; \
using std::cin; \
using std::cout; \
using std::endl; \
using nOT::nUtil::ToStr; 


// Please read and follow this syntax examples:
namespace nExamplesOfConvention { 
// Welcome, to the world of C++11 !

int gGlobalVariable; // g - global variable

class cFooBar {
private:
	static int sStaticVariable; // s - static variable
	
	int mFooBarBaz; // m - variable, member of class

	int Fooberize();
	int DerpTheHerp();
	
public:
	cFooBar(int x) 
	: mFooBarBaz(x)
	{}
	
	inline int Foo() {
		int abc=42;
		return abc;
	}
};
int cFooBar::sStaticVariable = 0;

// In case of simple parameters, we can skip "m" prefix. In this case:
struct cSimpleParam {
	int x;
	int y;
	
	cSimpleParam(int x, int y)
	: x(x), y(y)
	{}
};


} // namespace

// #####################################################################
// #####################################################################
// #####################################################################
// Utilities - various utils that are used in OT (but don't have to be related to OT)

extern std::string GetObjectName_global_string; // extern to h
std::string GetObjectName_global_string="(global)"; // definition/initialization
std::string GetObjectName() {	return GetObjectName_global_string; }

#define OT_CODE_STAMP ( ToStr("[") + ToStr(__FILE__) + ToStr(" +") + ToStr(__LINE__) + ToStr(" as ") + ToStr(__FUNCTION__) + (" of ") + ToStr(GetObjectName() + ToStr("]")) )

// TODO: move to utils
namespace nOT {
namespace nUtil { 

template <class T>
std::string ToStr(const T & obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

}
}

// ====================================================================

// TODO: move to own file
namespace nOT {
namespace nNewcli {

// list of thigs from libraries that we pull into namespace nOT::nNewcli
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;
using std::unique_ptr;
using std::cin;
using std::cout;
using std::endl;
using nOT::nUtil::ToStr;

/*

[Description_of_auto_completion]

Commands are in form:
topic, action, [--subaction] var1 var2 ... [argN1] [argN2] [--optionNameN[=][optionArgN]] 
<- cCmdname ---------------> <-------------------- arguments --------------------------->
<- cCmdname ---------------> <-- var ----> <-- extra var --> <-- option ---------------->
<- mandatory-----------------------------> <--- optional ------------------------------->

2..3 words of command name, 0..N mandatory variables, 0..N extra variables, any options

	- subaction will be probably not used but leaving such possibility to be flexible	
	
ARGUMENTS:
	- Arguments available depend on the command name.

	- Options for command depend on the command name, as well are imported from global.

	- Options can't be placed before variables!

	- Options can be unique or can repeat. Options can have no value/data,
		or can have one.This gives 2*2 = 4 kinds of options: uniq, uniqData, 
		repeat, repeatData 
		
	- Options can be both global and comming from selected action/subaction.

SEE testcases below in functions

msg     # error: incomplete action
msg send     # error: missing required options
msg send <mynym>     # error: missing required options
msg send <mynym> <hisnym>
msg send <mynym> <hisnym>
msg send <mynym> <hisnym>
msg send <mynym> <hisnym>
msg send <mynym> <hisnym> --push     # global option
msg send <mynym> <hisnym> --no-footer     # action option
msg send <mynym> <hisnym> --cc <ccnym>     # action option with value
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg ls
msg mv
msg rm <index>
nym 		# can display active (default) nym
nym ls 
nym new 
nym new <name>
nym rm <name>
nym rm <nymID>
msguard info   # test, imaginary comand "msguard" (microsoft guard) info - shows windows firewall status for OT tcp
 
*/


class cCmdname { // holds (2)-part name of command like "msg","send"
	// represents name of one command, including the (1)-2-3 components e.g. msg,send or msg,export,msg
	// "msg send"
	// "msg list"
	// "msg export msg"
	// "msg export all"
	// "msg" (not a valid command, will be used with null_function, is just to provide global options to inherit)

	protected:
		const string mTopic;
		const string mAction;
		const string mSubaction;

	public:
		cCmdname(const string &topic, const string &action, const string &subaction);
};

cCmdname::cCmdname(const string &topic, const string &action, const string &subaction) 
:mTopic(topic), mAction(action), mSubaction(subaction)
{
}


/*
Build:
Tree of max options:
[msg] ---------> { --unicode }
[msg send] ----> (2) + (3) + {--now,--later,--sign,--red} , msg_send_complete() 

msg_send_complete() {
	if (stage==arg) { if (arg_pos==1) get_my_nyms();    if (arg_pos==2) get_your_nyms(); }
	else if (stage==extra) { ... }
	else if (stage==option) {
		foreach (opt) ..
			if (--now) delete --later;
			if (uniq) delete this_option;
		} // existing options eliminate possibilities
		if (half_world) finish_option( remaining_options ); 
		else show_other_options();
	}
}
*/


/*
class argument_info {
	// klasa mowi jaki to argument  np ze to argument  "mynym" i ze ma byc stringiem albo ze ma byc integerem albo ze to tylko boolean 
	// oraz dostarcza klasa !!! do auto complete jakas
	
	string mName; // "mynym" "hisnym" (nawet te argumenty, ktore maja okreslona kolejnosc wiec niby nie maja nazwy, beda jak mialy dla jasnosci i np generowania tekstu help"

	// inne mName to bedzie np "cc"  dla opcji --cc ktora juz wymaga nazwy

};
*/

/*
typedef string argument_data ; // na razie...  

class cCmdoptions {

		// required arguments
		vector< argument_info > // ty ma być { ("msg","send")  ,  ("msg","send","body") itd tak jak w cCmdname::returnStandard

		map< argument_info , vector< argument_data > > // tu bedzie mapa, ktora np dla
}

class cCmdlineInfo {
	public:
	protected:
		vector<cCmdname> mPossible; // store here possible command names
		map<cCmdname , details_of_command> mPossibleDetails;
};
*/



} // namespace nNewcli
} // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################



// TODO: move to own file
namespace nOT {
namespace nOTHint {

// list of thigs from libraries that we pull into namespace nOT::nNewcli
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;
using std::unique_ptr;
using std::cin;
using std::cout;
using std::endl;
using nOT::nUtil::ToStr;

class cHint {
	public:

		vector<string> AutoComplete(const string &sofar_str) const; // the main function to auto-complete

	protected:
		vector<string> BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const; // return command lines tree that is possible from this place
};

vector<string> cHint::AutoComplete(const string &sofar_str) const { // the main function to auto-complete
	auto possible = BuildTreeOfCommandlines(sofar_str,false);
	return possible;
}


vector<string> cHint::BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const {
	std::istringstream iss(sofar_str);
	vector<string> sofar { std::istream_iterator<string>{iss}, std::istream_iterator<string>{} };
	// ^-- fine for now, but later needs to take into account "..." and slashes etc... use boost option?

	std::copy( sofar.begin() , sofar.end() ,  std::ostream_iterator<string>(std::cout, ", ") );

	auto namepart = sofar; // exactly 3 elements, with "" for missing elements
	// TODO split - limit to 3 on copy ^
	while (namepart.size()<3) namepart.push_back("");


	if (namepart.at(0)=="msg") {

		if (namepart.at(1)=="") {
			return vector<string>(1,"complete-1");
		} // msg ""

		else if (namepart.at(1)=="send") {

		} // msg send

		else if (namepart.at(1)=="del") {
		} // msg del

	} // msg

	else if (namepart.at(0)=="nym") {

	} // nym 

	else {
	}

/*
		// to be used in "main" to get list of possible command names:
		static vector<cCmdname> GetDefaultCommands() {
			v.push_back( cCmdlineInfo("msg","send") );
			v.push_back( cCmdlineInfo("msg","send","body") );
			v.push_back( cCmdlineInfo("msg","send","headers") );
			v.push_back( cCmdlineInfo("msg","list") );
			return v;
		}
		*/
	throw std::runtime_error("Unable to handle following completion: sofar_str='" + ToStr(sofar_str) + "' in " + OT_CODE_STAMP);
}

}; // namespace nOTHint
}; // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################

namespace nOT {
namespace nTests {

OT_COMMON_USING_NAMESPACE;

bool testcase_namespace_pollution();
bool testcase_cxx11_memory();
bool testcase_complete_1();

} // nTests
} // nOT



// ====================================================================
int main() {
	nOT::nTests::testcase_complete_1();
	nOT::nTests::testcase_namespace_pollution();
	nOT::nTests::testcase_cxx11_memory();

	// return 42; // nope. in C++, the exit code returns YOU
}
// ====================================================================

// #####################################################################
// #####################################################################
// #####################################################################

namespace nOT {
namespace nTests {


OT_COMMON_USING_NAMESPACE; // <========= NAMESPACE inclusion

bool testcase_complete_1() {
	map<string , vector<string> > const cases {
		 { "msg", { " uard", " send", " ls", " mv", " rm" } }
		,{ "msg ", { "send", "ls", "mv", "rm" } } 
		,{ "msg send", { " mynym", " hisnym" } }
		,{ "msg send ", { "mynym", "hisnym" } }
		,{ "msg ls", {  } }
		,{ "msg ls ", {  } }
		,{ "msg mv", {  } }
		,{ "msg mv ", {  } }
		,{ "msg rm", {  } }
		,{ "msg rm ", {  } }
		,{ "msguard", { " info" } }
		,{ "msguard ", { "info" } }
		,{ "nym" , { " ls", " new" , " rm"} }
		,{ "nym " , { "ls", "new" , "rm"} }
	};

	nOT::nOTHint::cHint hint; 
	hint.AutoComplete("msg send");

	bool ok = 1;

	return ok;
}

// ==================================================================
// ==================================================================
bool testcase_namespace_pollution() {
	class a {
	};

	using namespace nOT::nOTHint;

	#ifdef __unittest_mustfail_compile1
	{
		// using std::string; // without this
		string s; // <-- must be a compile error
	}
	#endif
	{
		using std::string; 
		string s; // <-- must work
	}

	return true;
}

bool testcase_cxx11_memory() {
	using namespace nOT::nNewcli;
	using namespace nOT::nOTHint;

	struct cObj {
			cObj() { cout<<"new"<<endl; }
			~cObj() { cout<<"delete"<<endl; }
	};

	unique_ptr<cObj> A( new cObj );

	return true;
}


} // nTest
} // nOT

