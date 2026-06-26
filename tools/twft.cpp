#include "traceweft/catalog.hpp"
#include "traceweft/csv.hpp"
#include "traceweft/diagnostics.hpp"
#include "traceweft/error.hpp"
#include "traceweft/json.hpp"
#include "traceweft/query.hpp"
#include "traceweft/stats.hpp"
#include "traceweft/timeline.hpp"
#include "traceweft/trace_file.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace traceweft;

static void usage() {
  std::cout << "twft inspect|verify|stats|query|export-json|catalog <args>\n";
}

static void writeText(const std::string& path, const std::string& text) {
  std::ofstream out(path);
  if (!out) throw IoError("cannot write " + path);
  out << text;
}

int main(int argc, char** argv) {
  try {
    if (argc < 2) {
      usage();
      return 1;
    }
    std::string cmd = argv[1];
    if (cmd == "catalog") {
      std::cout << CatalogSummary() << "\n";
      if (argc > 2) {
        for (const auto& e : SearchCatalog(argv[2])) {
          std::cout << e.service << " " << e.event << " " << e.category << "\n";
        }
      }
      return 0;
    }
    if (argc < 3) {
      usage();
      return 1;
    }
    TraceFile tf = ReadTraceFile(argv[2]);
    auto records = FlattenRecords(tf);
    if (cmd == "inspect") {
      std::cout << InspectTrace(tf);
    } else if (cmd == "verify") {
      auto d = DiagnoseTrace(tf);
      std::cout << FormatDiagnostics(d);
      return HighestDiagnosticLevel(d) >= 3 ? 2 : 0;
    } else if (cmd == "stats") {
      std::cout << FormatStats(ComputeStats(records));
    } else if (cmd == "query") {
      if (argc < 4) throw QueryError("query expression missing");
      auto q = ParseQuery(argv[3]);
      std::cout << RecordsToJson(FilterRecords(records, q)) << "\n";
    } else if (cmd == "export-json") {
      if (argc < 4) throw IoError("output path missing");
      writeText(argv[3], RecordsToJson(records));
    } else if (cmd == "timeline") {
      uint64_t width = argc > 3 ? std::stoull(argv[3]) : 1000;
      std::cout << FormatTimeline(BuildTimeline(records, width));
    } else {
      usage();
      return 1;
    }
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "twft: " << e.what() << "\n";
    return 2;
  }
}
