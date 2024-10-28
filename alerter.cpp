#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

class INetworkAlerter
{
public:
    virtual int networkAlert(float) = 0;
};

class NetworkAlerterStub : public INetworkAlerter{
    private:
    int returnValue = 200;

    public:
    NetworkAlerterStub(float retVal)
    {
        returnValue = retVal;
    }
    NetworkAlerterStub() = default;

    void setReturnValue(float newValue)
    {
        returnValue = newValue;
    }

    int networkAlert(float celcius){
        std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
        return returnValue;
    }
};

void alertInCelcius(float farenheit, INetworkAlerter& networkAlerter) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerter.networkAlert(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int main() {
    NetworkAlerterStub NetworkAlertStub;
    alertInCelcius(400.5, NetworkAlertStub);
    alertInCelcius(303.6, NetworkAlertStub);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 0);

    NetworkAlertStub.setReturnValue(500);
    alertInCelcius(400.5, NetworkAlertStub);
    alertInCelcius(303.6, NetworkAlertStub);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 2);

    std::cout << "All is well (maybe!)\n";
    return 0;
}
