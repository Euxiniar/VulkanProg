#include "Renderer.h"

#include <cstdlib>
#include <assert.h>
#include <vector>


Renderer::Renderer()
{
	_InitInstance();
}


Renderer::~Renderer()
{
	_DeInitInstance();
}

void Renderer::_InitInstance()
{
	VkApplicationInfo application_info{};
	application_info.sType						= VK_STRUCTURE_TYPE_APPLICATION_INFO;
	application_info.apiVersion					= VK_MAKE_VERSION(1, 0, 0);
	application_info.applicationVersion			= VK_MAKE_VERSION(1, 0, 0);
	application_info.pApplicationName			= "Vulkan Application";

	VkInstanceCreateInfo instance_create_info{};
	instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instance_create_info.pApplicationInfo = &application_info;


	auto err = vkCreateInstance(&instance_create_info, nullptr, &_instance);
	if (err != VK_SUCCESS)
	{
		assert(0 && "Vulkan ERROR: Create instance failed.");
		std::exit(-1);
	}
}

void Renderer::_DeInitInstance()
{
	vkDestroyInstance(_instance, nullptr);
	_instance = nullptr;
}

void Renderer::_InitDevice()
{
	{
		uint32_t gpu_count = 0;
		vkEnumeratePhysicalDevices(_instance, &gpu_count, nullptr);
		std::vector<VkPhysicalDevice> gpu_list(gpu_count);
		vkEnumeratePhysicalDevices(_instance, &gpu_count, gpu_list.data());
		_gpu = gpu_list[0];
	}

	float queue_priorities[]{1.0};
	VkDeviceQueueCreateInfo device_queue_create_info{};
	device_queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	device_queue_create_info.queueFamilyIndex = ;
	device_queue_create_info.queueCount = 1;
	device_queue_create_info.pQueuePriorities = queue_priorities;

	VkDeviceCreateInfo device_create_info{};
	device_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	device_create_info.queueCreateInfoCount = 1;
	device_create_info.pQueueCreateInfos = &device_queue_create_info;

	vkCreateDevice(_gpu, &device_create_info , nullptr, &_device);

}

void Renderer::_DeInitDevice()
{
}
