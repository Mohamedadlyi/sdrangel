///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef SDRBASE_CHANNEL_CHANNELWEBAPIUTILS_H_
#define SDRBASE_CHANNEL_CHANNELWEBAPIUTILS_H_

#include <QString>

#include "SWGDeviceSettings.h"
#include "SWGDeviceReport.h"
#include "SWGFeatureSettings.h"
#include "SWGFeatureReport.h"

#include "export.h"

class DeviceSet;
class Feature;

class SDRBASE_API ChannelWebAPIUtils
{
public:
    static bool getCenterFrequency(unsigned int deviceIndex, double &frequencyInHz);
    static bool setCenterFrequency(unsigned int deviceIndex, double frequencyInHz);
    static bool getLOPpmCorrection(unsigned int deviceIndex, int &ppmTenths);
    static bool setLOPpmCorrection(unsigned int deviceIndex, int ppmTenths);
    static bool getDevSampleRate(unsigned int deviceIndex, int &sampleRate);
    static bool setDevSampleRate(unsigned int deviceIndex, int sampleRate);
    static bool getGain(unsigned int deviceIndex, int stage, int &gain);
    static bool setGain(unsigned int deviceIndex, int stage, int gain);
    static bool getAGC(unsigned int deviceIndex, int &enabled);
    static bool setAGC(unsigned int deviceIndex, bool enabled);
    static bool getRFBandwidth(unsigned int deviceIndex, int &bw);
    static bool setRFBandwidth(unsigned int deviceIndex, int bw);
    static bool getSoftDecim(unsigned int deviceIndex, int &log2Decim);
    static bool setSoftDecim(unsigned int deviceIndex, int log2Decim);
    static bool getBiasTee(unsigned int deviceIndex, int &enabled);
    static bool setBiasTee(unsigned int deviceIndex, bool enabled);
    static bool getDCOffsetRemoval(unsigned int deviceIndex, int &enabled);
    static bool setDCOffsetRemoval(unsigned int deviceIndex, bool enabled);
    static bool getIQCorrection(unsigned int deviceIndex, int &enabled);
    static bool setIQCorrection(unsigned int deviceIndex, bool enabled);
    static bool run(unsigned int deviceIndex, int subsystemIndex=0);
    static bool stop(unsigned int deviceIndex, int subsystemIndex=0);
    static bool getFrequencyOffset(unsigned int deviceIndex, int channelIndex, int& offset);
    static bool setFrequencyOffset(unsigned int deviceIndex, int channelIndex, int offset);
    static bool startStopFileSinks(unsigned int deviceIndex, bool start);
    static bool satelliteAOS(const QString name, bool northToSouthPass, const QString &tle, QDateTime dateTime);
    static bool satelliteLOS(const QString name);
    static bool getDeviceSetting(unsigned int deviceIndex, const QString &setting, int &value);
    static bool getDeviceReportValue(unsigned int deviceIndex, const QString &key, QString &value);
    static bool getDeviceReportList(unsigned int deviceIndex, const QString &key, const QString &subKey, QList<int> &values);
    static bool patchDeviceSetting(unsigned int deviceIndex, const QString &setting, int value);
    static bool patchFeatureSetting(unsigned int featureSetIndex, unsigned int featureIndex, const QString &setting, const QString &value);
    static bool patchFeatureSetting(unsigned int featureSetIndex, unsigned int featureIndex, const QString &setting, double value);
    static bool getFeatureReportValue(unsigned int featureSetIndex, unsigned int featureIndex, const QString &key, int &value);
    static bool getFeatureReportValue(unsigned int featureSetIndex, unsigned int featureIndex, const QString &key, QString &value);    
protected:
    static bool getDeviceSettings(unsigned int deviceIndex, SWGSDRangel::SWGDeviceSettings &deviceSettingsResponse, DeviceSet *&deviceSet);
    static bool getDeviceReport(unsigned int deviceIndex, SWGSDRangel::SWGDeviceReport &deviceReport);
    static bool getFeatureSettings(unsigned int featureSetIndex, unsigned int featureIndex, SWGSDRangel::SWGFeatureSettings &featureSettingsResponse, Feature *&feature);
    static bool getFeatureReport(unsigned int featureSetIndex, unsigned int featureIndex, SWGSDRangel::SWGFeatureReport &featureReport);
    static QString getDeviceHardwareId(unsigned int deviceIndex);
};

#endif // SDRBASE_CHANNEL_CHANNELWEBAPIUTILS_H_
