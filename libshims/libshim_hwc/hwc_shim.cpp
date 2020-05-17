#include <ui/GraphicBufferMapper.h>
#include <ui/PixelFormat.h>
#include <ui/Rect.h>
#include <log/log.h>
#include <dlfcn.h>
#include <string.h>
#include <iostream>

#include <math.h>

/*
#include <cutils/process_name.h>
#include <cutils/properties.h>
#include <utils/String8.h>
#include <utils/KeyedVector.h>
#include <utils/Singleton.h>
*/

#define LOG_TAG "DECKER_SHIM"

extern "C" {

// Missing GrapicBufferProducer symbol
void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE() {
}

void _ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv(buffer_handle_t handle, int usage, const android::Rect& bounds, void** vaddr) {
    _ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv(handle, static_cast<uint32_t>(usage), bounds, vaddr);
}

long long __eabi_d21z(double var) {
    return (long long)floor(var);
}

}
