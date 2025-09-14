#pragma once
#include <vulkan/vulkan.h>
#include "str.hpp"

#ifdef MINIMALIB_VK_ALLOC
constexpr static VkAllocationCallbacks* C_VK_ALLOC { MINIMALIB_VK_ALLOC };
#else
constexpr static VkAllocationCallbacks* C_VK_ALLOC { nullptr };
#endif

namespace
{
VkResult vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, VkDevice* pDevice) noexcept
{ return vkCreateDevice(physicalDevice, pCreateInfo, C_VK_ALLOC, pDevice); }
VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, VkInstance* pInstance) noexcept
{ return vkCreateInstance(pCreateInfo, C_VK_ALLOC, pInstance); }
VkResult vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, VkSemaphore* pSemaphore) noexcept
{ return vkCreateSemaphore(device, pCreateInfo, C_VK_ALLOC, pSemaphore); }
VkResult vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, VkEvent* pEvent) noexcept
{ return vkCreateEvent(device, pCreateInfo, C_VK_ALLOC, pEvent); }
VkResult vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, VkQueryPool* pQueryPool) noexcept
{ return vkCreateQueryPool(device, pCreateInfo, C_VK_ALLOC, pQueryPool); }
VkResult vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, VkBuffer* pBuffer) noexcept
{ return vkCreateBuffer(device, pCreateInfo, C_VK_ALLOC, pBuffer); }
VkResult vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, VkBufferView* pView) noexcept
{ return vkCreateBufferView(device, pCreateInfo, C_VK_ALLOC, pView); }
VkResult vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, VkImage* pImage) noexcept
{ return vkCreateImage(device, pCreateInfo, C_VK_ALLOC, pImage); }
VkResult vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount) noexcept
{ return vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, nullptr); }
VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount) noexcept
{ return ::vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, nullptr); }
VkResult vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount) noexcept
{ return vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, nullptr); }
VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount) noexcept
{ return ::vkEnumerateInstanceLayerProperties(pPropertyCount, nullptr); }
VkResult vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount) noexcept
{ return vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, nullptr); }
VkResult vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, VkDeviceMemory* pMemory) noexcept
{ return vkAllocateMemory(device, pAllocateInfo, C_VK_ALLOC, pMemory); }
VkResult vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, VkImageView* pView) noexcept
{ return vkCreateImageView(device, pCreateInfo, C_VK_ALLOC, pView); }
VkResult vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModule* pShaderModule) noexcept
{ return vkCreateShaderModule(device, pCreateInfo, C_VK_ALLOC, pShaderModule); }
VkResult vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, VkPipelineCache* pPipelineCache) noexcept
{ return vkCreatePipelineCache(device, pCreateInfo, C_VK_ALLOC, pPipelineCache); }
VkResult vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize) noexcept
{ return vkGetPipelineCacheData(device, pipelineCache, pDataSize, nullptr); }
VkResult vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, VkPipeline* pPipelines) noexcept
{ return vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, C_VK_ALLOC, pPipelines); }
VkResult vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, VkPipeline* pPipelines) noexcept
{ return vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, C_VK_ALLOC, pPipelines); }
VkResult vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, VkPipelineLayout* pPipelineLayout) noexcept
{ return vkCreatePipelineLayout(device, pCreateInfo, C_VK_ALLOC, pPipelineLayout); }
VkResult vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, VkSampler* pSampler) noexcept
{ return vkCreateSampler(device, pCreateInfo, C_VK_ALLOC, pSampler); }
VkResult vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayout* pSetLayout) noexcept
{ return vkCreateDescriptorSetLayout(device, pCreateInfo, C_VK_ALLOC, pSetLayout); }
VkResult vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, VkDescriptorPool* pDescriptorPool) noexcept
{ return vkCreateDescriptorPool(device, pCreateInfo, C_VK_ALLOC, pDescriptorPool); }
VkResult vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, VkFramebuffer* pFramebuffer) noexcept
{ return vkCreateFramebuffer(device, pCreateInfo, C_VK_ALLOC, pFramebuffer); }
VkResult vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, VkRenderPass* pRenderPass) noexcept
{ return vkCreateRenderPass(device, pCreateInfo, C_VK_ALLOC, pRenderPass); }
VkResult vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, VkCommandPool* pCommandPool) noexcept
{ return vkCreateCommandPool(device, pCreateInfo, C_VK_ALLOC, pCommandPool); }
VkResult vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, VkFence* pFence) noexcept
{ return vkCreateFence(device, pCreateInfo, C_VK_ALLOC, pFence); }

void vkDestroyInstance(VkInstance instance) noexcept
{    vkDestroyInstance(instance, C_VK_ALLOC); }
void vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount) noexcept
{    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, nullptr); }
void vkDestroyDevice(VkDevice device) noexcept
{    vkDestroyDevice(device, C_VK_ALLOC); }
void vkFreeMemory(VkDevice device, VkDeviceMemory memory) noexcept
{    vkFreeMemory(device, memory, C_VK_ALLOC); }
void vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount) noexcept
{    vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, nullptr); }
void vkDestroyFence(VkDevice device, VkFence fence) noexcept
{    vkDestroyFence(device, fence, C_VK_ALLOC); }
void vkDestroySemaphore(VkDevice device, VkSemaphore semaphore) noexcept
{    vkDestroySemaphore(device, semaphore, C_VK_ALLOC); }
void vkDestroyEvent(VkDevice device, VkEvent event) noexcept
{    vkDestroyEvent(device, event, C_VK_ALLOC); }
void vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool) noexcept
{    vkDestroyQueryPool(device, queryPool, C_VK_ALLOC); }
void vkDestroyBuffer(VkDevice device, VkBuffer buffer) noexcept
{    vkDestroyBuffer(device, buffer, C_VK_ALLOC); }
void vkDestroyBufferView(VkDevice device, VkBufferView bufferView) noexcept
{    vkDestroyBufferView(device, bufferView, C_VK_ALLOC); }
void vkDestroyImage(VkDevice device, VkImage image) noexcept
{    vkDestroyImage(device, image, C_VK_ALLOC); }
void vkDestroyImageView(VkDevice device, VkImageView imageView) noexcept
{    vkDestroyImageView(device, imageView, C_VK_ALLOC); }
void vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule) noexcept
{    vkDestroyShaderModule(device, shaderModule, C_VK_ALLOC); }
void vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache) noexcept
{    vkDestroyPipelineCache(device, pipelineCache, C_VK_ALLOC); }
void vkDestroyPipeline(VkDevice device, VkPipeline pipeline) noexcept
{    vkDestroyPipeline(device, pipeline, C_VK_ALLOC); }
void vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout) noexcept
{    vkDestroyPipelineLayout(device, pipelineLayout, C_VK_ALLOC); }
void vkDestroySampler(VkDevice device, VkSampler sampler) noexcept
{    vkDestroySampler(device, sampler, C_VK_ALLOC); }
void vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout) noexcept
{    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, C_VK_ALLOC); }
void vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool) noexcept
{    vkDestroyDescriptorPool(device, descriptorPool, C_VK_ALLOC); }
void vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer) noexcept
{    vkDestroyFramebuffer(device, framebuffer, C_VK_ALLOC); }
void vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass) noexcept
{    vkDestroyRenderPass(device, renderPass, C_VK_ALLOC); }
void vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool) noexcept
{    vkDestroyCommandPool(device, commandPool, C_VK_ALLOC); }
} // namespace

constexpr static str_t to_string(VkResult result)
{	switch(result)
	{
	case VK_SUCCESS:                                            return str("VK_SUCCESS");
	case VK_NOT_READY:                                          return str("VK_NOT_READY");
	case VK_TIMEOUT:                                            return str("VK_TIMEOUT");
	case VK_EVENT_SET:                                          return str("VK_EVENT_SET");
	case VK_EVENT_RESET:                                        return str("VK_EVENT_RESET");
	case VK_INCOMPLETE:                                         return str("VK_INCOMPLETE");
	case VK_ERROR_OUT_OF_HOST_MEMORY:                           return str("VK_ERROR_OUT_OF_HOST_MEMORY");
	case VK_ERROR_OUT_OF_DEVICE_MEMORY:                         return str("VK_ERROR_OUT_OF_DEVICE_MEMORY");
	case VK_ERROR_INITIALIZATION_FAILED:                        return str("VK_ERROR_INITIALIZATION_FAILED");
	case VK_ERROR_DEVICE_LOST:                                  return str("VK_ERROR_DEVICE_LOST");
	case VK_ERROR_MEMORY_MAP_FAILED:                            return str("VK_ERROR_MEMORY_MAP_FAILED");
	case VK_ERROR_LAYER_NOT_PRESENT:                            return str("VK_ERROR_LAYER_NOT_PRESENT");
	case VK_ERROR_EXTENSION_NOT_PRESENT:                        return str("VK_ERROR_EXTENSION_NOT_PRESENT");
	case VK_ERROR_FEATURE_NOT_PRESENT:                          return str("VK_ERROR_FEATURE_NOT_PRESENT");
	case VK_ERROR_INCOMPATIBLE_DRIVER:                          return str("VK_ERROR_INCOMPATIBLE_DRIVER");
	case VK_ERROR_TOO_MANY_OBJECTS:                             return str("VK_ERROR_TOO_MANY_OBJECTS");
	case VK_ERROR_FORMAT_NOT_SUPPORTED:                         return str("VK_ERROR_FORMAT_NOT_SUPPORTED");
	case VK_ERROR_FRAGMENTED_POOL:                              return str("VK_ERROR_FRAGMENTED_POOL");
	case VK_ERROR_UNKNOWN:                                      return str("VK_ERROR_UNKNOWN");
	case VK_ERROR_OUT_OF_POOL_MEMORY:                           return str("VK_ERROR_OUT_OF_POOL_MEMORY");
	case VK_ERROR_INVALID_EXTERNAL_HANDLE:                      return str("VK_ERROR_INVALID_EXTERNAL_HANDLE");
	case VK_ERROR_FRAGMENTATION:                                return str("VK_ERROR_FRAGMENTATION");
	case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:               return str("VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS");
	case VK_PIPELINE_COMPILE_REQUIRED:                          return str("VK_PIPELINE_COMPILE_REQUIRED");
	case VK_ERROR_NOT_PERMITTED:                                return str("VK_ERROR_NOT_PERMITTED");
	case VK_ERROR_SURFACE_LOST_KHR:                             return str("VK_ERROR_SURFACE_LOST_KHR");
	case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:                     return str("VK_ERROR_NATIVE_WINDOW_IN_USE_KHR");
	case VK_SUBOPTIMAL_KHR:                                     return str("VK_SUBOPTIMAL_KHR");
	case VK_ERROR_OUT_OF_DATE_KHR:                              return str("VK_ERROR_OUT_OF_DATE_KHR");
	case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:                     return str("VK_ERROR_INCOMPATIBLE_DISPLAY_KHR");
	case VK_ERROR_VALIDATION_FAILED_EXT:                        return str("VK_ERROR_VALIDATION_FAILED_EXT");
	case VK_ERROR_INVALID_SHADER_NV:                            return str("VK_ERROR_INVALID_SHADER_NV");
	case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:                return str("VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR");
	case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:       return str("VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR");
	case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:    return str("VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR");
	case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:       return str("VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR");
	case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:        return str("VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR");
	case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:          return str("VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR");
	case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: return str("VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT");
	case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:          return str("VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT");
	case VK_THREAD_IDLE_KHR:                                    return str("VK_THREAD_IDLE_KHR");
	case VK_THREAD_DONE_KHR:                                    return str("VK_THREAD_DONE_KHR");
	case VK_OPERATION_DEFERRED_KHR:                             return str("VK_OPERATION_DEFERRED_KHR");
	case VK_OPERATION_NOT_DEFERRED_KHR:                         return str("VK_OPERATION_NOT_DEFERRED_KHR");
	case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR:             return str("VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR");
	case VK_ERROR_COMPRESSION_EXHAUSTED_EXT:                    return str("VK_ERROR_COMPRESSION_EXHAUSTED_EXT");
	case VK_INCOMPATIBLE_SHADER_BINARY_EXT:                     return str("VK_INCOMPATIBLE_SHADER_BINARY_EXT");
	case VK_PIPELINE_BINARY_MISSING_KHR:                        return str("VK_PIPELINE_BINARY_MISSING_KHR");
	case VK_ERROR_NOT_ENOUGH_SPACE_KHR:                         return str("VK_ERROR_NOT_ENOUGH_SPACE_KHR");
	default:                                                    return str("UNKNOWN");
	}
}
constexpr static str_t to_string(VkPhysicalDeviceType type)
{	switch(type)
	{
	case VK_PHYSICAL_DEVICE_TYPE_OTHER:          return str("OTHER");
	case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return str("INTEGRATED GPU");
	case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   return str("DISCRETE GPU");
	case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    return str("VIRTUAL GPU");
	case VK_PHYSICAL_DEVICE_TYPE_CPU:            return str("CPU");
	default:                                     return str("UNKNOWN");
	}
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

