#include <proton/base.hpp>
#include <proton/ref.hpp>
#include <proton/deque.hpp>
#include <proton/string.hpp>
#include <proton/tuple.hpp>

using namespace std;
using namespace proton;

void str_eg()
{
    cout << ">>> str examples :" << endl;

    str a="def ghi";
    a="abc "+a;
    deque_<str> s=a.split();

    cout << "split:" << s << endl;
    PROTON_THROW_IF(a.split()[-1]!="ghi", "split error");
    PROTON_THROW_IF(s[0]+" "+s[1]+" "+s[2]!=a, "split error");

    str b=str(" ").join(s);
    cout << "join again:"<< b << endl;
    PROTON_THROW_IF(a!=b, "join error");

    str A=a.upper();
    cout << "upper:"<<A<< endl;
    PROTON_THROW_IF(A!="ABC DEF GHI", "upper error");

    cout << "lower:"<<A.lower()<< endl;
    PROTON_THROW_IF(A.lower()!=a, "lower error");

    PROTON_THROW_IF(!a.startswith("abc"), "startswith error");
    PROTON_THROW_IF(!A.istartswith("abc"), "istartswith error");

    PROTON_THROW_IF(!A.endswith("GHI"), "endswith error");
    PROTON_THROW_IF(!a.iendswith("GHI"), "iendswith error");

    cout << "There is " << A.count('A') << " 'A' in A." << endl;
    PROTON_THROW_IF(A.count('A')!=1, "count error");
    PROTON_THROW_IF(A.index('A')!=0, "index error");

    str c="  abc  ";
    cout << "strip of '" << c << "' is " ;
    cout << c.strip() << endl;
    PROTON_THROW_IF(c.strip()!="abc", "strip error");

    cout << str("%% to show a number: %d\n") % 15;
    cout << str("%% to show a float: %f\n") % 15.1;
    cout << "%% to show a str: %s\n" % str("abc");
    cout << "%% to show a tuple: (%d,%d)\n" % _t(1,2);

    int k=10;
    cout << "%% to show a forwarded tuple: (%s,%f,%X)" % _f(c,1.1,k) << endl;

    bool caught=false;
    try{
        cout << str("%d %d %o %% %x %X\n") % 1;
    }
    catch(const std::invalid_argument& e)
    {
        // catch more formats
        cout << e.what() << endl;
        caught=true;
    }
    PROTON_THROW_IF(!caught, "bad catch more formats");

    caught=false;
    try{
        cout << "%d %d %o %% %x %X\n" % _f(1,2,3);
    }
    catch(const std::invalid_argument& e)
    {
        // catch more formats for tuple
        cout << e.what() << endl;
        caught=true;
    }
    PROTON_THROW_IF(!caught, "bad catch more formats for tuple");

    caught=false;
    try{
        cout << "%d %d" % _f(1,2,3);
    }
    catch(const std::invalid_argument& e)
    {
        // catch extra parameters
        cout << e.what() << endl;
        caught=true;
    }
    PROTON_THROW_IF(!caught, "bad catch extra parameters");

    caught=false;
    try{
        cout << "%d %d" % _f("abc",2);
    }
    catch(const std::invalid_argument& e)
    {
        // catch bad type
        cout << e.what() << endl;
        caught=true;
    }
    PROTON_THROW_IF(!caught, "bad catch unmatch type");

    caught=false;
    try{
        cout << "%t %d" % _f("abc",2);
    }
    catch(const std::invalid_argument& e)
    {
        // catch bad type
        cout << e.what() << endl;
        caught=true;
    }
    PROTON_THROW_IF(!caught, "bad catch unknown type");
}

void wstr_eg()
{
    wcout << L">>> wstr examples :" << endl;

    wstr a=L"def ghi";
    a=L"abc "+a;
    deque_<wstr> s=a.split();

    wcout << L"split:" << s << endl;
    PROTON_THROW_IF(a.split()[-1]!=L"ghi", "split error");
    PROTON_THROW_IF(s[0]+L" "+s[1]+L" "+s[2]!=a, "split error");

    wstr b=wstr(L" ").join(s);
    wcout << L"join again:"<< b << endl;
    PROTON_THROW_IF(a!=b, "join error");

    wstr A=a.upper();
    wcout << L"upper:"<<A<< endl;
    PROTON_THROW_IF(A!=L"ABC DEF GHI", "upper error");

    wcout << L"lower:"<<A.lower()<< endl;
    PROTON_THROW_IF(A.lower()!=a, "lower error");

    PROTON_THROW_IF(!a.startswith(L"abc"), "startswith error");
    PROTON_THROW_IF(!A.istartswith(L"abc"), "istartswith error");

    PROTON_THROW_IF(!A.endswith(L"GHI"), "endswith error");
    PROTON_THROW_IF(!a.iendswith(L"GHI"), "iendswith error");

    wcout << L"There is " << A.count(L'A') << L" 'A' in A." << endl;
    PROTON_THROW_IF(A.count(L'A')!=1, "count error");
    PROTON_THROW_IF(A.index(L'A')!=0, "index error");

    wstr c=L"  abc  ";
    wcout << L"strip of '" << c << L"' is " ;
    wcout << c.strip() << endl;
    PROTON_THROW_IF(c.strip()!=L"abc", "strip error");

    cout << str("%% to show a number: %d\n") % 15;
    cout << str("%% to show a float: %f\n") % 15.1;
    cout << "%% to show a str: %s\n" % str("abc");
    cout << "%% to show a tuple: (%d,%d)\n" % _t(1,2);

    int k=10;
    wcout << L"%% to show a forwarded tuple: (%s,%f,%X)" % _f(c,1.1,k) << endl;


    try{
        wcout << wstr(L"%d %d %o %% %x %X\n") % 1;
    }
    catch(const std::invalid_argument& e)
    {
        // catch more formats
        cout << e.what() << endl;
    }
    try{
        wcout << L"%d %d %o %% %x %X\n" % _f(1,2,3);
    }
    catch(const std::invalid_argument& e)
    {
        // catch more formats for tuple
        cout << e.what() << endl;
    }
    try{
        wcout << L"%d %d" % _f(1,2,3);
    }
    catch(const std::invalid_argument& e)
    {
        // catch extra parameters
        cout << e.what() << endl;
    }
    try{
        wcout << L"%d %d" % _f(L"abc",2);
    }
    catch(const std::invalid_argument& e)
    {
        // catch bad type
        cout << e.what() << endl;
    }
    try{
        wcout << L"%t %d" % _f(L"abc",2);
    }
    catch(const std::invalid_argument& e)
    {
        // catch bad type
        cout << e.what() << endl;
    }
}

int main()
{
    str_eg();
    wstr_eg();
    return 0;
}

