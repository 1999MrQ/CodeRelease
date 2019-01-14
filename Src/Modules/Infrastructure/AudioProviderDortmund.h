/**
 * @file AudioProvider.cpp
 * This file declares a module that provides audio samples.
 * @author Thomas Röfer
 */

#pragma once

#ifdef TARGET_ROBOT
#include <alsa/asoundlib.h>
#else
#include <ctime>
#include <cstdio>
#include "Platform/File.h"
#endif
#include "Tools/Module/Module.h"
#include "Representations/Infrastructure/AudioData.h"
#include "Representations/Infrastructure/GameInfo.h"
#include "Representations/Infrastructure/FrameInfo.h"
#include "Representations/MotionControl/MotionInfo.h"

MODULE(AudioProviderDortmund,
{ ,
  REQUIRES(GameInfo),
  REQUIRES(FrameInfo),
  REQUIRES(MotionInfo),
  PROVIDES_WITHOUT_MODIFY(AudioDataDortmund),
  DEFINES_PARAMETERS(
  {,
    (unsigned)(10) retries, /**< Number of tries to open device. */
    (unsigned)(500) retryDelay, /**< Delay before a retry to open device. */
    (unsigned)(1) channels, /**< Number of channels to capture. */
    (unsigned)(22050) sampleRate, //44100/2 hz /**< Sample rate to capture. This variable will contain the framerate the driver finally selected. */
    (unsigned)(10000) maxFrames, /**< Maximum number of frames read in one cycle. */
    (bool)(false) connectionEstablished, /**< is set during initializing sound card connection */
    (bool)(false) simulateWhistleInSimulator, /**< if enabled a whistle sound is send in set to robots inside the simulator */
    (int)(-1) simulateSinusInSimulator,
    (float)(0.0f) simulateNoiseInSimulator,
  }),
});

class AudioProviderDortmund : public AudioProviderDortmundBase
{
private:
#ifdef TARGET_ROBOT
  snd_pcm_t* handle;
#else
  FILE * audioFile;
  unsigned timestamp;
#endif
  void update(AudioDataDortmund& audioData);

public:
  /**
  * Default constructor.
  */
  AudioProviderDortmund();

  /**
  * Destructor.
  */
  ~AudioProviderDortmund();
};
