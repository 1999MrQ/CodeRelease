/**
  * @file PNGLogger.h
  * This file declares a module that writes all camera images to PNG files.
  * @author Fabian Rensen
 **/

#pragma once
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Tools/Module/Module.h"
#include "Representations/Infrastructure/Image.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#endif
#include "Tools/ImageProcessing/stb_image.h"
#include "Tools/ImageProcessing/stb_image_write.h"
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include "Representations/Perception/CNN/PNGImage.h"
#include "Platform/File.h"
#include <string>
#include "Tools/ColorModelConversions.h"
#include <time.h>


MODULE(PNGLogger,
{,
  REQUIRES(Image),
  REQUIRES(ImageUpper),
  PROVIDES(PNGImageDummy),

  LOADS_PARAMETERS(
  {,
    (bool) enabled,
    (bool) streamAsRGB,
    (int) everyXFrame,
  }),
});


class PNGLogger : public PNGLoggerBase
{
public:
  PNGLogger();

private:
  void update(PNGImageDummy& dummy);

  std::string getFilePath();

  std::string filepath;

  void logImage(bool upper);
  void logImageYFull(bool upper);
  void logImageY(bool upper);

  std::string getDate();

  int imageCounter = 0;

  std::string theDate;

  unsigned char targetLower[320*240*3];
  unsigned char targetUpper[640*480*3];

  unsigned char targetLowerFull[640*480*3];
  unsigned char targetUpperFull[1280*960*3];

};
