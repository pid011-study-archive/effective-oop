#include <iostream>
#include <string>

using namespace std;

class InputSystemImpl
{
public:
    virtual ~InputSystemImpl() = default;
    virtual void setInputInfo(string inputString) const = 0;
};

class WindowsInputSystemImpl : public InputSystemImpl
{
public:
    void setInputInfo(std::string inputString) const override
    {
        cout << "Windows setInputInfo" << endl;
    }
};

class AOSInputSystemImpl : public InputSystemImpl
{
public:
    void setInputInfo(string inputString) const override
    {
        cout << "AOS setInputInfo" << endl;
    }
};

class IOSInputSystemImpl : public InputSystemImpl
{
public:
    void setInputInfo(string inputString) const override
    {
        cout << "iOS setInputInfo" << endl;
    }
};

class InputSystem
{
public:
    InputSystem(const InputSystemImpl& inputSystemImpl) : pImpl(inputSystemImpl) { }
    virtual ~InputSystem() = default;
    virtual void setInputData(string data) const = 0;

protected:
    const InputSystemImpl& pImpl;
};

class ControllerInputSystem : public InputSystem
{
public:
    ControllerInputSystem(int inputBufferNum, const InputSystemImpl& inputSystemImpl)
        : InputSystem(inputSystemImpl), bufferNum(inputBufferNum) { }

    void setInputData(string data) const override
    {
        return pImpl.setInputInfo(data);
    }

    int getInputDataNum() const
    {
        return bufferNum;
    }

private:
    int bufferNum;
};

class GamePadInputSystem : public InputSystem
{
public:
    GamePadInputSystem(int deviceNum, const InputSystemImpl& inputSystemImpl)
        : InputSystem(inputSystemImpl), gamepadNum(deviceNum) { }

    void setInputData(string data) const override
    {
        return pImpl.setInputInfo(data);
    }

    int getGamePadNum() const
    {
        return gamepadNum;
    }

    void printDeviceNum() const
    {
        cout << "device: " << gamepadNum << endl;
    }

private:
    int gamepadNum;
};

int main()
{
    GamePadInputSystem padInputSystem(10, WindowsInputSystemImpl {});
    ControllerInputSystem controllerInputSystem(20, AOSInputSystemImpl {});

    padInputSystem.printDeviceNum();
    controllerInputSystem.setInputData("ctrl");
    padInputSystem.setInputData("jor");
}
