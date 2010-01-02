/**
 *  @file univhac.h
 *
 *  @date 1-jan-2010
 *  @author Ives van der Flaas
 *
 *   Copyright 2010 (c) Ives van der Flaas
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0 unless required by
 *   applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *   WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions
 *   and limitations under the License.
 */

#ifndef UNIVHAC_H_
#define UNIVHAC_H_

////////////////////////////////////////////////////////////////////////
////////////////////////////// UNIX ////////////////////////////////////
////////////////////////////////////////////////////////////////////////
#ifdef __unix__
#include <sys/time.h>

class Univhac
{
public:
	Univhac()
	{
		gettimeofday(&last, 0);
	}

	double poll() const
	{
		timeval now;

		gettimeofday(&now, 0);

		return now.tv_sec-last.tv_sec + (now.tv_usec - last.tv_usec)/1000000.0;
	}

	double reset()
	{
		timeval now;
		gettimeofday(&now, 0);

		const double rv = now.tv_sec-last.tv_sec + (now.tv_usec - last.tv_usec)/1000000.0;

		last = now;

		return rv;

	}
private:
	timeval last;
};


////////////////////////////////////////////////////////////////////////
//////////////////////////// WINDOWS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////
#else

#include "windows.h"

class Univhac
{
public:
	Univhac()
	{
		if(QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&prevCount)) == 0)
			throw std::string("Cannot run QueryPerformanceCounter...");

		if(QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&countsPerSec)) == 0)
			throw std::string("Cannot QueryPerformanceFrequency...");

	}

	double poll() const
	{
		__int64 now;

		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&now));
		return double(now-prevCount)/double(countsPerSec);

	}

	double reset()
	{
		__int64 now;

		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&now));
		double result = double(now-prevCount)/double(countsPerSec);
		prevCount = now;
		return result;

	}

private:
	__int64 prevCount;
	__int64 countsPerSec;

};

#endif // not unix


#endif /* UNIVHAC_H_ */






