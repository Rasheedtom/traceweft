
#include "traceweft/diagnostics.hpp"
#include <sstream>
namespace traceweft {
std::vector<Diagnostic> DiagnoseTrace(const TraceFile& trace){
 std::vector<Diagnostic> out;
 for(const auto& issue:VerifyTrace(trace)) out.push_back({
"warning","verify",issue}
);
 if(trace.segments.empty()) out.push_back({
"info","empty","trace has no event segments"}
);
 for(const auto& s:trace.segments){
 if(s.records.empty()) out.push_back({
"info","empty-segment","segment contains no records"}
);
 if(s.info.size==0) out.push_back({
"warning","zero-segment","segment size is zero"}
);
 }
 return out;
 }
std::string FormatDiagnostics(const std::vector<Diagnostic>& ds){
 std::ostringstream os;
 for(const auto& d:ds) os<<d.severity<<" "<<d.code<<": "<<d.message<<"\n";
 return os.str();
 }
int HighestDiagnosticLevel(const std::vector<Diagnostic>& ds){
 int level=0;
 for(const auto& d:ds){
 if(d.severity=="error") level=std::max(level,3);
 else if(d.severity=="warning") level=std::max(level,2);
 else level=std::max(level,1);
 }
 return level;
 }
}
