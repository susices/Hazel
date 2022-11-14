#pragma once
#include "Hazel/Core.h"
namespace Hazel
{
    class HAZEL_API Input
    {
    public:
        static bool IsKeyPressed(int keyCode){return s_Instance->IsKeyPressedImpl(keyCode);}

    protected:
        virtual bool IsKeyPressedImpl(int keyCode) = 0;
        
    private:
        static Input* s_Instance;
    };
}
