#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	printf("Init Hazel Engine\n");
	Hazel::Log::Init();
	HZ_CORE_WARN("Init Log!");
	HZ_INFO("Hello {}  Haha!","YY");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif // HZ_PLATFORM_WINDOWS


