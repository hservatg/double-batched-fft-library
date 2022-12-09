// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: BSD-3-Clause

#include "vkfft_error.hpp"

#include <utility>

vkfft_error::vkfft_error(std::string what, VkFFTResult status)
    : what_(std::move(what)), status_(status) {}
vkfft_error::vkfft_error(char const *what, VkFFTResult status) : what_(what), status_(status) {}

char const *vkfft_result_to_string(VkFFTResult status) {
    switch (status) {
    case VKFFT_SUCCESS:
        return "VKFFT_SUCCESS";
    case VKFFT_ERROR_MALLOC_FAILED:
        return "VKFFT_ERROR_MALLOC_FAILED";
    case VKFFT_ERROR_INSUFFICIENT_CODE_BUFFER:
        return "VKFFT_ERROR_INSUFFICIENT_CODE_BUFFER";
    case VKFFT_ERROR_INSUFFICIENT_TEMP_BUFFER:
        return "VKFFT_ERROR_INSUFFICIENT_TEMP_BUFFER";
    case VKFFT_ERROR_PLAN_NOT_INITIALIZED:
        return "VKFFT_ERROR_PLAN_NOT_INITIALIZED";
    case VKFFT_ERROR_NULL_TEMP_PASSED:
        return "VKFFT_ERROR_NULL_TEMP_PASSED";
    case VKFFT_ERROR_INVALID_PHYSICAL_DEVICE:
        return "VKFFT_ERROR_INVALID_PHYSICAL_DEVICE";
    case VKFFT_ERROR_INVALID_DEVICE:
        return "VKFFT_ERROR_INVALID_DEVICE";
    case VKFFT_ERROR_INVALID_QUEUE:
        return "VKFFT_ERROR_INVALID_QUEUE";
    case VKFFT_ERROR_INVALID_COMMAND_POOL:
        return "VKFFT_ERROR_INVALID_COMMAND_POOL";
    case VKFFT_ERROR_INVALID_FENCE:
        return "VKFFT_ERROR_INVALID_FENCE";
    case VKFFT_ERROR_ONLY_FORWARD_FFT_INITIALIZED:
        return "VKFFT_ERROR_ONLY_FORWARD_FFT_INITIALIZED";
    case VKFFT_ERROR_ONLY_INVERSE_FFT_INITIALIZED:
        return "VKFFT_ERROR_ONLY_INVERSE_FFT_INITIALIZED";
    case VKFFT_ERROR_INVALID_CONTEXT:
        return "VKFFT_ERROR_INVALID_CONTEXT";
    case VKFFT_ERROR_INVALID_PLATFORM:
        return "VKFFT_ERROR_INVALID_PLATFORM";
    case VKFFT_ERROR_ENABLED_saveApplicationToString:
        return "VKFFT_ERROR_ENABLED_saveApplicationToString";
    case VKFFT_ERROR_EMPTY_FILE:
        return "VKFFT_ERROR_EMPTY_FILE";
    case VKFFT_ERROR_EMPTY_FFTdim:
        return "VKFFT_ERROR_EMPTY_FFTdim";
    case VKFFT_ERROR_EMPTY_size:
        return "VKFFT_ERROR_EMPTY_size";
    case VKFFT_ERROR_EMPTY_bufferSize:
        return "VKFFT_ERROR_EMPTY_bufferSize";
    case VKFFT_ERROR_EMPTY_buffer:
        return "VKFFT_ERROR_EMPTY_buffer";
    case VKFFT_ERROR_EMPTY_tempBufferSize:
        return "VKFFT_ERROR_EMPTY_tempBufferSize";
    case VKFFT_ERROR_EMPTY_tempBuffer:
        return "VKFFT_ERROR_EMPTY_tempBuffer";
    case VKFFT_ERROR_EMPTY_inputBufferSize:
        return "VKFFT_ERROR_EMPTY_inputBufferSize";
    case VKFFT_ERROR_EMPTY_inputBuffer:
        return "VKFFT_ERROR_EMPTY_inputBuffer";
    case VKFFT_ERROR_EMPTY_outputBufferSize:
        return "VKFFT_ERROR_EMPTY_outputBufferSize";
    case VKFFT_ERROR_EMPTY_outputBuffer:
        return "VKFFT_ERROR_EMPTY_outputBuffer";
    case VKFFT_ERROR_EMPTY_kernelSize:
        return "VKFFT_ERROR_EMPTY_kernelSize";
    case VKFFT_ERROR_EMPTY_kernel:
        return "VKFFT_ERROR_EMPTY_kernel";
    case VKFFT_ERROR_EMPTY_applicationString:
        return "VKFFT_ERROR_EMPTY_applicationString";
    case VKFFT_ERROR_UNSUPPORTED_RADIX:
        return "VKFFT_ERROR_UNSUPPORTED_RADIX";
    case VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH:
        return "VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH";
    case VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH_R2C:
        return "VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH_R2C";
    case VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH_DCT:
        return "VKFFT_ERROR_UNSUPPORTED_FFT_LENGTH_DCT";
    case VKFFT_ERROR_UNSUPPORTED_FFT_OMIT:
        return "VKFFT_ERROR_UNSUPPORTED_FFT_OMIT";
    case VKFFT_ERROR_FAILED_TO_ALLOCATE:
        return "VKFFT_ERROR_FAILED_TO_ALLOCATE";
    case VKFFT_ERROR_FAILED_TO_MAP_MEMORY:
        return "VKFFT_ERROR_FAILED_TO_MAP_MEMORY";
    case VKFFT_ERROR_FAILED_TO_ALLOCATE_COMMAND_BUFFERS:
        return "VKFFT_ERROR_FAILED_TO_ALLOCATE_COMMAND_BUFFERS";
    case VKFFT_ERROR_FAILED_TO_BEGIN_COMMAND_BUFFER:
        return "VKFFT_ERROR_FAILED_TO_BEGIN_COMMAND_BUFFER";
    case VKFFT_ERROR_FAILED_TO_END_COMMAND_BUFFER:
        return "VKFFT_ERROR_FAILED_TO_END_COMMAND_BUFFER";
    case VKFFT_ERROR_FAILED_TO_SUBMIT_QUEUE:
        return "VKFFT_ERROR_FAILED_TO_SUBMIT_QUEUE";
    case VKFFT_ERROR_FAILED_TO_WAIT_FOR_FENCES:
        return "VKFFT_ERROR_FAILED_TO_WAIT_FOR_FENCES";
    case VKFFT_ERROR_FAILED_TO_RESET_FENCES:
        return "VKFFT_ERROR_FAILED_TO_RESET_FENCES";
    case VKFFT_ERROR_FAILED_TO_CREATE_DESCRIPTOR_POOL:
        return "VKFFT_ERROR_FAILED_TO_CREATE_DESCRIPTOR_POOL";
    case VKFFT_ERROR_FAILED_TO_CREATE_DESCRIPTOR_SET_LAYOUT:
        return "VKFFT_ERROR_FAILED_TO_CREATE_DESCRIPTOR_SET_LAYOUT";
    case VKFFT_ERROR_FAILED_TO_ALLOCATE_DESCRIPTOR_SETS:
        return "VKFFT_ERROR_FAILED_TO_ALLOCATE_DESCRIPTOR_SETS";
    case VKFFT_ERROR_FAILED_TO_CREATE_PIPELINE_LAYOUT:
        return "VKFFT_ERROR_FAILED_TO_CREATE_PIPELINE_LAYOUT";
    case VKFFT_ERROR_FAILED_SHADER_PREPROCESS:
        return "VKFFT_ERROR_FAILED_SHADER_PREPROCESS";
    case VKFFT_ERROR_FAILED_SHADER_PARSE:
        return "VKFFT_ERROR_FAILED_SHADER_PARSE";
    case VKFFT_ERROR_FAILED_SHADER_LINK:
        return "VKFFT_ERROR_FAILED_SHADER_LINK";
    case VKFFT_ERROR_FAILED_SPIRV_GENERATE:
        return "VKFFT_ERROR_FAILED_SPIRV_GENERATE";
    case VKFFT_ERROR_FAILED_TO_CREATE_SHADER_MODULE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_SHADER_MODULE";
    case VKFFT_ERROR_FAILED_TO_CREATE_INSTANCE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_INSTANCE";
    case VKFFT_ERROR_FAILED_TO_SETUP_DEBUG_MESSENGER:
        return "VKFFT_ERROR_FAILED_TO_SETUP_DEBUG_MESSENGER";
    case VKFFT_ERROR_FAILED_TO_FIND_PHYSICAL_DEVICE:
        return "VKFFT_ERROR_FAILED_TO_FIND_PHYSICAL_DEVICE";
    case VKFFT_ERROR_FAILED_TO_CREATE_DEVICE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_DEVICE";
    case VKFFT_ERROR_FAILED_TO_CREATE_FENCE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_FENCE";
    case VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_POOL:
        return "VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_POOL";
    case VKFFT_ERROR_FAILED_TO_CREATE_BUFFER:
        return "VKFFT_ERROR_FAILED_TO_CREATE_BUFFER";
    case VKFFT_ERROR_FAILED_TO_ALLOCATE_MEMORY:
        return "VKFFT_ERROR_FAILED_TO_ALLOCATE_MEMORY";
    case VKFFT_ERROR_FAILED_TO_BIND_BUFFER_MEMORY:
        return "VKFFT_ERROR_FAILED_TO_BIND_BUFFER_MEMORY";
    case VKFFT_ERROR_FAILED_TO_FIND_MEMORY:
        return "VKFFT_ERROR_FAILED_TO_FIND_MEMORY";
    case VKFFT_ERROR_FAILED_TO_SYNCHRONIZE:
        return "VKFFT_ERROR_FAILED_TO_SYNCHRONIZE";
    case VKFFT_ERROR_FAILED_TO_COPY:
        return "VKFFT_ERROR_FAILED_TO_COPY";
    case VKFFT_ERROR_FAILED_TO_CREATE_PROGRAM:
        return "VKFFT_ERROR_FAILED_TO_CREATE_PROGRAM";
    case VKFFT_ERROR_FAILED_TO_COMPILE_PROGRAM:
        return "VKFFT_ERROR_FAILED_TO_COMPILE_PROGRAM";
    case VKFFT_ERROR_FAILED_TO_GET_CODE_SIZE:
        return "VKFFT_ERROR_FAILED_TO_GET_CODE_SIZE";
    case VKFFT_ERROR_FAILED_TO_GET_CODE:
        return "VKFFT_ERROR_FAILED_TO_GET_CODE";
    case VKFFT_ERROR_FAILED_TO_DESTROY_PROGRAM:
        return "VKFFT_ERROR_FAILED_TO_DESTROY_PROGRAM";
    case VKFFT_ERROR_FAILED_TO_LOAD_MODULE:
        return "VKFFT_ERROR_FAILED_TO_LOAD_MODULE";
    case VKFFT_ERROR_FAILED_TO_GET_FUNCTION:
        return "VKFFT_ERROR_FAILED_TO_GET_FUNCTION";
    case VKFFT_ERROR_FAILED_TO_SET_DYNAMIC_SHARED_MEMORY:
        return "VKFFT_ERROR_FAILED_TO_SET_DYNAMIC_SHARED_MEMORY";
    case VKFFT_ERROR_FAILED_TO_MODULE_GET_GLOBAL:
        return "VKFFT_ERROR_FAILED_TO_MODULE_GET_GLOBAL";
    case VKFFT_ERROR_FAILED_TO_LAUNCH_KERNEL:
        return "VKFFT_ERROR_FAILED_TO_LAUNCH_KERNEL";
    case VKFFT_ERROR_FAILED_TO_EVENT_RECORD:
        return "VKFFT_ERROR_FAILED_TO_EVENT_RECORD";
    case VKFFT_ERROR_FAILED_TO_ADD_NAME_EXPRESSION:
        return "VKFFT_ERROR_FAILED_TO_ADD_NAME_EXPRESSION";
    case VKFFT_ERROR_FAILED_TO_INITIALIZE:
        return "VKFFT_ERROR_FAILED_TO_INITIALIZE";
    case VKFFT_ERROR_FAILED_TO_SET_DEVICE_ID:
        return "VKFFT_ERROR_FAILED_TO_SET_DEVICE_ID";
    case VKFFT_ERROR_FAILED_TO_GET_DEVICE:
        return "VKFFT_ERROR_FAILED_TO_GET_DEVICE";
    case VKFFT_ERROR_FAILED_TO_CREATE_CONTEXT:
        return "VKFFT_ERROR_FAILED_TO_CREATE_CONTEXT";
    case VKFFT_ERROR_FAILED_TO_CREATE_PIPELINE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_PIPELINE";
    case VKFFT_ERROR_FAILED_TO_SET_KERNEL_ARG:
        return "VKFFT_ERROR_FAILED_TO_SET_KERNEL_ARG";
    case VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_QUEUE:
        return "VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_QUEUE";
    case VKFFT_ERROR_FAILED_TO_RELEASE_COMMAND_QUEUE:
        return "VKFFT_ERROR_FAILED_TO_RELEASE_COMMAND_QUEUE";
    case VKFFT_ERROR_FAILED_TO_ENUMERATE_DEVICES:
        return "VKFFT_ERROR_FAILED_TO_ENUMERATE_DEVICES";
    case VKFFT_ERROR_FAILED_TO_GET_ATTRIBUTE:
        return "VKFFT_ERROR_FAILED_TO_GET_ATTRIBUTE";
    case VKFFT_ERROR_FAILED_TO_CREATE_EVENT:
        return "VKFFT_ERROR_FAILED_TO_CREATE_EVENT";
    case VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_LIST:
        return "VKFFT_ERROR_FAILED_TO_CREATE_COMMAND_LIST";
    case VKFFT_ERROR_FAILED_TO_DESTROY_COMMAND_LIST:
        return "VKFFT_ERROR_FAILED_TO_DESTROY_COMMAND_LIST";
    case VKFFT_ERROR_FAILED_TO_SUBMIT_BARRIER:
        return "VKFFT_ERROR_FAILED_TO_SUBMIT_BARRIER";
    default:
        return "unknown status code";
    }
}