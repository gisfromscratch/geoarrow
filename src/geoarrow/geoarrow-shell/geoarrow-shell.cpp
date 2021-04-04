// Copyright 2020 Jan Tschada
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "geoarrow-shell.h"
#include "record.h"
#include "record_filter.h"

using namespace arrow::csv;
using namespace arrow::io;
using namespace io;
using namespace geoarrow;
using namespace std;

static void read_csv()
{
	const unsigned int column_count = 19;
	CSVReader<column_count, trim_chars<'\t'>> geonames_reader("cities1000_50.txt");
	//geonames_reader.read_header(ignore_no_column, "GeonameId", "Name", "ASCIIName", "AlternateNames", "Latitude", "Longitude");
	geonames_reader.set_header("GeonameId",
		"Name",
		"ASCIIName",
		"AlternateNames",
		"Latitude",
		"Longitude",
		"FeatureClass",
		"FeatureCode",
		"CountryCode",
		"AlternateCountryCodes",
		"Admin1Code",
		"Admin2Code",
		"Admin3Code",
		"Admin4Code",
		"Population",
		"Elevation",
		"DEM",
		"Timezone",
		"ModificationDate");

	string geoname_id;
	string name;
	string ascii_name;
	string alternate_names;
	double latitude;
	double longitude;
	string feature_class;
	string feature_code;
	string country_code;
	string alternate_country_codes;
	string admin1_code;
	string admin2_code;
	string admin3_code;
	string admin4_code;
	int population;
	int elevation;
	string dem;
	string timezone;
	string modification_date;
	while (geonames_reader.read_row(geoname_id,
		name,
		ascii_name,
		alternate_names,
		latitude,
		longitude,
		feature_class,
		feature_code,
		country_code,
		alternate_country_codes,
		admin1_code,
		admin2_code,
		admin3_code,
		admin4_code,
		population,
		elevation,
		dem,
		timezone,
		modification_date))
	{

	}
}

static void read_lines()
{
	const size_t latitude_index = 4;
	const size_t longitude_index = 5;
	const size_t country_code_index = 8;

	attribute_record_filter record_filter;
	pair<string, string> country_code_restriction = make_pair("CountryCode", "AD");
	record_filter.add_equals(country_code_restriction);

	LineReader geonames_reader("cities1000_50.txt");
	while (char* line = geonames_reader.next_line())
	{
		record geonames_record;
		double latitude;
		double longitude;

		regex geonames_pattern("\\t");
		string geonames_line(line);
		sregex_token_iterator token_it(geonames_line.begin(), geonames_line.end(), geonames_pattern, -1);
		sregex_token_iterator token_it_end;
		for (size_t token_index = 0; token_it != token_it_end; ++token_it, ++token_index)
		{
			switch (token_index)
			{
			case latitude_index:
				latitude = atof((*token_it).str().c_str());
				break;

			case longitude_index:
				longitude = atof((*token_it).str().c_str());
				break;

			case country_code_index:
				{
					pair<string, string> country_code = make_pair("CountryCode", (*token_it).str());
					geonames_record.set_value(country_code);
				}
				break;
			}
		}

		if (record_filter.filter(&geonames_record))
		{
			cout << "New record filtered . . ." << endl;
		}
	}
}

static void read_lines_arrow()
{
	auto memory_pool = arrow::default_memory_pool();
	//shared_ptr<arrow::io::ReadableFile> file;
}



int main(int argc, char* argv[])
{
	read_lines();

	cout << "Hello geoarrow . . ." << endl;
	return 0;
}
