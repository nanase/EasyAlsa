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
/*
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation; either version 2.1 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#ifndef ALSAOUT_H
#define	ALSAOUT_H

#ifdef __HTOD__
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
#else
#include <stdint.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

  /** PCM sample format */
  typedef enum _alsaPcmFormat_t {
    /** Unknown */
    ALSA_PCM_FORMAT_UNKNOWN = -1,
    /** Signed 8 bit */
    ALSA_PCM_FORMAT_S8 = 0,
    /** Unsigned 8 bit */
    ALSA_PCM_FORMAT_U8,
    /** Signed 16 bit Little Endian */
    ALSA_PCM_FORMAT_S16_LE,
    /** Signed 16 bit Big Endian */
    ALSA_PCM_FORMAT_S16_BE,
    /** Unsigned 16 bit Little Endian */
    ALSA_PCM_FORMAT_U16_LE,
    /** Unsigned 16 bit Big Endian */
    ALSA_PCM_FORMAT_U16_BE,
    /** Signed 24 bit Little Endian using low three bytes in 32-bit word */
    ALSA_PCM_FORMAT_S24_LE,
    /** Signed 24 bit Big Endian using low three bytes in 32-bit word */
    ALSA_PCM_FORMAT_S24_BE,
    /** Unsigned 24 bit Little Endian using low three bytes in 32-bit word */
    ALSA_PCM_FORMAT_U24_LE,
    /** Unsigned 24 bit Big Endian using low three bytes in 32-bit word */
    ALSA_PCM_FORMAT_U24_BE,
    /** Signed 32 bit Little Endian */
    ALSA_PCM_FORMAT_S32_LE,
    /** Signed 32 bit Big Endian */
    ALSA_PCM_FORMAT_S32_BE,
    /** Unsigned 32 bit Little Endian */
    ALSA_PCM_FORMAT_U32_LE,
    /** Unsigned 32 bit Big Endian */
    ALSA_PCM_FORMAT_U32_BE,
    /** Float 32 bit Little Endian, Range -1.0 to 1.0 */
    ALSA_PCM_FORMAT_FLOAT_LE,
    /** Float 32 bit Big Endian, Range -1.0 to 1.0 */
    ALSA_PCM_FORMAT_FLOAT_BE,
    /** Float 64 bit Little Endian, Range -1.0 to 1.0 */
    ALSA_PCM_FORMAT_FLOAT64_LE,
    /** Float 64 bit Big Endian, Range -1.0 to 1.0 */
    ALSA_PCM_FORMAT_FLOAT64_BE,
    /** IEC-958 Little Endian */
    ALSA_PCM_FORMAT_IEC958_SUBFRAME_LE,
    /** IEC-958 Big Endian */
    ALSA_PCM_FORMAT_IEC958_SUBFRAME_BE,
    /** Mu-Law */
    ALSA_PCM_FORMAT_MU_LAW,
    /** A-Law */
    ALSA_PCM_FORMAT_A_LAW,
    /** Ima-ADPCM */
    ALSA_PCM_FORMAT_IMA_ADPCM,
    /** MPEG */
    ALSA_PCM_FORMAT_MPEG,
    /** GSM */
    ALSA_PCM_FORMAT_GSM,
    /** Special */
    ALSA_PCM_FORMAT_SPECIAL = 31,
    /** Signed 24bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_S24_3LE = 32,
    /** Signed 24bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_S24_3BE,
    /** Unsigned 24bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_U24_3LE,
    /** Unsigned 24bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_U24_3BE,
    /** Signed 20bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_S20_3LE,
    /** Signed 20bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_S20_3BE,
    /** Unsigned 20bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_U20_3LE,
    /** Unsigned 20bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_U20_3BE,
    /** Signed 18bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_S18_3LE,
    /** Signed 18bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_S18_3BE,
    /** Unsigned 18bit Little Endian in 3bytes format */
    ALSA_PCM_FORMAT_U18_3LE,
    /** Unsigned 18bit Big Endian in 3bytes format */
    ALSA_PCM_FORMAT_U18_3BE,
    /* G.723 (ADPCM) 24 kbit/s, 8 samples in 3 bytes */
    ALSA_PCM_FORMAT_G723_24,
    /* G.723 (ADPCM) 24 kbit/s, 1 sample in 1 byte */
    ALSA_PCM_FORMAT_G723_24_1B,
    /* G.723 (ADPCM) 40 kbit/s, 8 samples in 3 bytes */
    ALSA_PCM_FORMAT_G723_40,
    /* G.723 (ADPCM) 40 kbit/s, 1 sample in 1 byte */
    ALSA_PCM_FORMAT_G723_40_1B,
    /* Direct Stream Digital (DSD) in 1-byte samples (x8) */
    ALSA_PCM_FORMAT_DSD_U8,
    /* Direct Stream Digital (DSD) in 2-byte samples (x16) */
    ALSA_PCM_FORMAT_DSD_U16_LE,
    ALSA_PCM_FORMAT_LAST = ALSA_PCM_FORMAT_DSD_U16_LE,

#if __BYTE_ORDER == __LITTLE_ENDIAN
    /** Signed 16 bit CPU endian */
    ALSA_PCM_FORMAT_S16 = ALSA_PCM_FORMAT_S16_LE,
    /** Unsigned 16 bit CPU endian */
    ALSA_PCM_FORMAT_U16 = ALSA_PCM_FORMAT_U16_LE,
    /** Signed 24 bit CPU endian */
    ALSA_PCM_FORMAT_S24 = ALSA_PCM_FORMAT_S24_LE,
    /** Unsigned 24 bit CPU endian */
    ALSA_PCM_FORMAT_U24 = ALSA_PCM_FORMAT_U24_LE,
    /** Signed 32 bit CPU endian */
    ALSA_PCM_FORMAT_S32 = ALSA_PCM_FORMAT_S32_LE,
    /** Unsigned 32 bit CPU endian */
    ALSA_PCM_FORMAT_U32 = ALSA_PCM_FORMAT_U32_LE,
    /** Float 32 bit CPU endian */
    ALSA_PCM_FORMAT_FLOAT = ALSA_PCM_FORMAT_FLOAT_LE,
    /** Float 64 bit CPU endian */
    ALSA_PCM_FORMAT_FLOAT64 = ALSA_PCM_FORMAT_FLOAT64_LE,
    /** IEC-958 CPU Endian */
    ALSA_PCM_FORMAT_IEC958_SUBFRAME = ALSA_PCM_FORMAT_IEC958_SUBFRAME_LE
#elif __BYTE_ORDER == __BIG_ENDIAN
    /** Signed 16 bit CPU endian */
    ALSA_PCM_FORMAT_S16 = ALSA_PCM_FORMAT_S16_BE,
    /** Unsigned 16 bit CPU endian */
    ALSA_PCM_FORMAT_U16 = ALSA_PCM_FORMAT_U16_BE,
    /** Signed 24 bit CPU endian */
    ALSA_PCM_FORMAT_S24 = ALSA_PCM_FORMAT_S24_BE,
    /** Unsigned 24 bit CPU endian */
    ALSA_PCM_FORMAT_U24 = ALSA_PCM_FORMAT_U24_BE,
    /** Signed 32 bit CPU endian */
    ALSA_PCM_FORMAT_S32 = ALSA_PCM_FORMAT_S32_BE,
    /** Unsigned 32 bit CPU endian */
    ALSA_PCM_FORMAT_U32 = ALSA_PCM_FORMAT_U32_BE,
    /** Float 32 bit CPU endian */
    ALSA_PCM_FORMAT_FLOAT = ALSA_PCM_FORMAT_FLOAT_BE,
    /** Float 64 bit CPU endian */
    ALSA_PCM_FORMAT_FLOAT64 = ALSA_PCM_FORMAT_FLOAT64_BE,
    /** IEC-958 CPU Endian */
    ALSA_PCM_FORMAT_IEC958_SUBFRAME = ALSA_PCM_FORMAT_IEC958_SUBFRAME_BE
#else
#error "Unknown endian"
#endif
  } alsaPcmFormat_t;

  /** PCM state */
  typedef enum _alsaPcmState_t {
    /** Open */
    ALSA_PCM_STATE_OPEN = 0,
    /** Setup installed */
    ALSA_PCM_STATE_SETUP,
    /** Ready to start */
    ALSA_PCM_STATE_PREPARED,
    /** Running */
    ALSA_PCM_STATE_RUNNING,
    /** Stopped: underrun (playback) or overrun (capture) detected */
    ALSA_PCM_STATE_XRUN,
    /** Draining: running (playback) or stopped (capture) */
    ALSA_PCM_STATE_DRAINING,
    /** Paused */
    ALSA_PCM_STATE_PAUSED,
    /** Hardware is suspended */
    ALSA_PCM_STATE_SUSPENDED,
    /** Hardware is disconnected */
    ALSA_PCM_STATE_DISCONNECTED,
    ALSA_PCM_STATE_LAST = ALSA_PCM_STATE_DISCONNECTED
  } alsaPcmState_t;

#define ALSA_OUT_DEFAULT "default"

  int32_t alsaOutOpen(void **handle, const char *deviceName);
  int32_t alsaOutClose(void *handle);
  int32_t alsaOutSetParams(void *handle,
          alsaPcmFormat_t format,
          uint32_t channels,
          uint32_t rate,
          uint32_t latency);
  int32_t alsaOutWrite(void *handle, const void *buffer, uint32_t size);
  int32_t alsaOutRecover(void *handle, int32_t error);
  int32_t alsaOutRecoverDebug(void *handle, int32_t error, int32_t silent);

  int32_t alsaOutStart(void *handle);
  int32_t alsaOutPause(void *handle, int32_t enable);
  int32_t alsaOutResume(void *handle);

  int32_t alsaOutDrop(void *handle);
  int32_t alsaOutDrain(void *handle);
  int32_t alsaOutReset(void *handle);
  int32_t alsaOutStatus(void *handle, alsaPcmState_t *status);
  int32_t alsaOutWait(void *handle, int32_t timeout);

  const char *alsaErrorString(int32_t errornum);

#ifdef	__cplusplus
}
#endif

#endif	/* ALSAOUT_H */

