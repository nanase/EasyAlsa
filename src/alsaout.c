/* LICENSE - The MIT License (MIT)

Copyright (c) 2014 Tomona Nanase

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#define ALSA_PCM_NEW_HW_PARAMS_API

#include <alsa/asoundlib.h>
#include "../include/alsaout.h"

int32_t alsaOutOpen(void **handle, const char *deviceName) {
  return snd_pcm_open((snd_pcm_t **) handle,
          deviceName == NULL ? ALSA_OUT_DEFAULT : deviceName,
          SND_PCM_STREAM_PLAYBACK,
          0);
}

int32_t alsaOutClose(void *handle) {
  return snd_pcm_close(handle);
}

int32_t alsaOutSetParams(void *handle,
        alsaPcmFormat_t format,
        uint32_t channels,
        uint32_t rate,
        uint32_t latency) {
  return snd_pcm_set_params(handle,
          (snd_pcm_format_t) format,
          SND_PCM_ACCESS_RW_INTERLEAVED,
          channels,
          rate,
          1,
          latency);
}

int32_t alsaOutWrite(void *handle, const void *buffer, uint32_t size) {
  return snd_pcm_writei(handle, buffer, size);
}

int32_t alsaOutRecover(void *handle, int32_t error) {
  return snd_pcm_recover(handle, error, 1);
}

int32_t alsaOutRecoverDebug(void *handle, int32_t error, int32_t silent) {
  return snd_pcm_recover(handle, error, silent);
}

int32_t alsaOutStart(void *handle) {
  return snd_pcm_start(handle);
}

int32_t alsaOutPause(void *handle, int32_t enable) {
  return snd_pcm_pause(handle, enable);
}

int32_t alsaOutResume(void *handle) {
  return snd_pcm_resume(handle);
}

int32_t alsaOutDrop(void *handle) {
  return snd_pcm_drop(handle);
}

int32_t alsaOutDrain(void *handle) {
  return snd_pcm_drain(handle);
}

int32_t alsaOutReset(void *handle) {
  return snd_pcm_reset(handle);
}

int32_t alsaOutStatus(void *handle, alsaPcmState_t *status) {
  return snd_pcm_status(handle, (snd_pcm_status_t *) status);
}

int32_t alsaOutWait(void *handle, int32_t timeout) {
  return snd_pcm_wait(handle, timeout);
}

const char *alsaErrorString(int32_t errornum) {
  return snd_strerror(errornum);
}