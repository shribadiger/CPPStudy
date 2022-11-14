#include <iostream>
using namespace std;

class VpiInterface
{
public:
    int _refCount;
    virtual ~VpiInterface() {}
    struct OAuthToken
    {
        std::string token;
    };
    virtual OAuthToken getToken() = 0;
};

class DummyInterface : public VpiInterface
{
public:
    DummyInterface() {}
    virtual ~DummyInterface() override {}
    OAuthToken getToken() { return OAuthToken(); }
};

int main()
{
    DummyInterface obj;
    obj.getToken();
    return 0;
}