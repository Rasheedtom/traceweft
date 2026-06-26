
#pragma once
#include <string>
#include <vector>
#include "traceweft/trace_file.hpp"
namespace traceweft {
struct Diagnostic {
 std::string severity;
 std::string code;
 std::string message;
 }
;
std::vector<Diagnostic> DiagnoseTrace(const TraceFile& trace);
std::string FormatDiagnostics(const std::vector<Diagnostic>& diagnostics);
int HighestDiagnosticLevel(const std::vector<Diagnostic>& diagnostics);
}
