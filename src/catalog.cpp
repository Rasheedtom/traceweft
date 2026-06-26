#include "traceweft/catalog.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
namespace traceweft {
namespace {
std::string Lower(std::string text) {
  for (char& ch : text) {
    ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
  }
  return text;
}
const std::vector<CatalogEntry>& Entries() {
  static const std::vector<CatalogEntry> entries = {
    CatalogEntry{
      "ingest",
      "batch.accepted",
      5,
      "workflow",
      "ingest accepted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.started",
      0,
      "workflow",
      "ingest started batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.completed",
      1,
      "io",
      "ingest completed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.failed",
      2,
      "query",
      "ingest failed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.retried",
      3,
      "io",
      "ingest retried batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.skipped",
      4,
      "security",
      "ingest skipped batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.expired",
      5,
      "planning",
      "ingest expired batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.refreshed",
      0,
      "resource",
      "ingest refreshed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.rotated",
      1,
      "quality",
      "ingest rotated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.sealed",
      2,
      "quality",
      "ingest sealed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.opened",
      3,
      "resource",
      "ingest opened batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.closed",
      4,
      "consistency",
      "ingest closed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.validated",
      5,
      "io",
      "ingest validated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.rejected",
      0,
      "io",
      "ingest rejected batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.throttled",
      1,
      "planning",
      "ingest throttled batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.promoted",
      2,
      "planning",
      "ingest promoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.demoted",
      3,
      "planning",
      "ingest demoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.merged",
      4,
      "planning",
      "ingest merged batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.split",
      5,
      "planning",
      "ingest split batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "batch.evicted",
      0,
      "resource",
      "ingest evicted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.accepted",
      3,
      "workflow",
      "ingest accepted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.started",
      4,
      "workflow",
      "ingest started segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.completed",
      5,
      "io",
      "ingest completed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.failed",
      0,
      "query",
      "ingest failed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.retried",
      1,
      "io",
      "ingest retried segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.skipped",
      2,
      "security",
      "ingest skipped segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.expired",
      3,
      "planning",
      "ingest expired segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.refreshed",
      4,
      "resource",
      "ingest refreshed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.rotated",
      5,
      "quality",
      "ingest rotated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.sealed",
      0,
      "quality",
      "ingest sealed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.opened",
      1,
      "resource",
      "ingest opened segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.closed",
      2,
      "consistency",
      "ingest closed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.validated",
      3,
      "io",
      "ingest validated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.rejected",
      4,
      "io",
      "ingest rejected segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.throttled",
      5,
      "planning",
      "ingest throttled segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.promoted",
      0,
      "planning",
      "ingest promoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.demoted",
      1,
      "planning",
      "ingest demoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.merged",
      2,
      "planning",
      "ingest merged segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.split",
      3,
      "planning",
      "ingest split segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "segment.evicted",
      4,
      "resource",
      "ingest evicted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.accepted",
      2,
      "workflow",
      "ingest accepted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.started",
      3,
      "workflow",
      "ingest started checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.completed",
      4,
      "io",
      "ingest completed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.failed",
      5,
      "query",
      "ingest failed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.retried",
      0,
      "io",
      "ingest retried checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.skipped",
      1,
      "security",
      "ingest skipped checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.expired",
      2,
      "planning",
      "ingest expired checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.refreshed",
      3,
      "resource",
      "ingest refreshed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.rotated",
      4,
      "quality",
      "ingest rotated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.sealed",
      5,
      "quality",
      "ingest sealed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.opened",
      0,
      "resource",
      "ingest opened checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.closed",
      1,
      "consistency",
      "ingest closed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.validated",
      2,
      "io",
      "ingest validated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.rejected",
      3,
      "io",
      "ingest rejected checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.throttled",
      4,
      "planning",
      "ingest throttled checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.promoted",
      5,
      "planning",
      "ingest promoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.demoted",
      0,
      "planning",
      "ingest demoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.merged",
      1,
      "planning",
      "ingest merged checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.split",
      2,
      "planning",
      "ingest split checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "checkpoint.evicted",
      3,
      "resource",
      "ingest evicted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.accepted",
      5,
      "workflow",
      "ingest accepted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.started",
      0,
      "workflow",
      "ingest started lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.completed",
      1,
      "io",
      "ingest completed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.failed",
      2,
      "query",
      "ingest failed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.retried",
      3,
      "io",
      "ingest retried lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.skipped",
      4,
      "security",
      "ingest skipped lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.expired",
      5,
      "planning",
      "ingest expired lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.refreshed",
      0,
      "resource",
      "ingest refreshed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.rotated",
      1,
      "quality",
      "ingest rotated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.sealed",
      2,
      "quality",
      "ingest sealed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.opened",
      3,
      "resource",
      "ingest opened lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.closed",
      4,
      "consistency",
      "ingest closed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.validated",
      5,
      "io",
      "ingest validated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.rejected",
      0,
      "io",
      "ingest rejected lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.throttled",
      1,
      "planning",
      "ingest throttled lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.promoted",
      2,
      "planning",
      "ingest promoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.demoted",
      3,
      "planning",
      "ingest demoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.merged",
      4,
      "planning",
      "ingest merged lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.split",
      5,
      "planning",
      "ingest split lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "lease.evicted",
      0,
      "resource",
      "ingest evicted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.accepted",
      1,
      "workflow",
      "ingest accepted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.started",
      2,
      "workflow",
      "ingest started token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.completed",
      3,
      "io",
      "ingest completed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.failed",
      4,
      "query",
      "ingest failed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.retried",
      5,
      "io",
      "ingest retried token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.skipped",
      0,
      "security",
      "ingest skipped token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.expired",
      1,
      "planning",
      "ingest expired token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.refreshed",
      2,
      "resource",
      "ingest refreshed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.rotated",
      3,
      "quality",
      "ingest rotated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.sealed",
      4,
      "quality",
      "ingest sealed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.opened",
      5,
      "resource",
      "ingest opened token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.closed",
      0,
      "consistency",
      "ingest closed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.validated",
      1,
      "io",
      "ingest validated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.rejected",
      2,
      "io",
      "ingest rejected token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.throttled",
      3,
      "planning",
      "ingest throttled token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.promoted",
      4,
      "planning",
      "ingest promoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.demoted",
      5,
      "planning",
      "ingest demoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.merged",
      0,
      "planning",
      "ingest merged token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.split",
      1,
      "planning",
      "ingest split token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "token.evicted",
      2,
      "resource",
      "ingest evicted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.accepted",
      4,
      "workflow",
      "ingest accepted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.started",
      5,
      "workflow",
      "ingest started stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.completed",
      0,
      "io",
      "ingest completed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.failed",
      1,
      "query",
      "ingest failed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.retried",
      2,
      "io",
      "ingest retried stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.skipped",
      3,
      "security",
      "ingest skipped stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.expired",
      4,
      "planning",
      "ingest expired stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.refreshed",
      5,
      "resource",
      "ingest refreshed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.rotated",
      0,
      "quality",
      "ingest rotated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.sealed",
      1,
      "quality",
      "ingest sealed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.opened",
      2,
      "resource",
      "ingest opened stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.closed",
      3,
      "consistency",
      "ingest closed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.validated",
      4,
      "io",
      "ingest validated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.rejected",
      5,
      "io",
      "ingest rejected stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.throttled",
      0,
      "planning",
      "ingest throttled stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.promoted",
      1,
      "planning",
      "ingest promoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.demoted",
      2,
      "planning",
      "ingest demoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.merged",
      3,
      "planning",
      "ingest merged stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.split",
      4,
      "planning",
      "ingest split stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "stream.evicted",
      5,
      "resource",
      "ingest evicted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.accepted",
      0,
      "workflow",
      "ingest accepted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.started",
      1,
      "workflow",
      "ingest started cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.completed",
      2,
      "io",
      "ingest completed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.failed",
      3,
      "query",
      "ingest failed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.retried",
      4,
      "io",
      "ingest retried cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.skipped",
      5,
      "security",
      "ingest skipped cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.expired",
      0,
      "planning",
      "ingest expired cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.refreshed",
      1,
      "resource",
      "ingest refreshed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.rotated",
      2,
      "quality",
      "ingest rotated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.sealed",
      3,
      "quality",
      "ingest sealed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.opened",
      4,
      "resource",
      "ingest opened cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.closed",
      5,
      "consistency",
      "ingest closed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.validated",
      0,
      "io",
      "ingest validated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.rejected",
      1,
      "io",
      "ingest rejected cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.throttled",
      2,
      "planning",
      "ingest throttled cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.promoted",
      3,
      "planning",
      "ingest promoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.demoted",
      4,
      "planning",
      "ingest demoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.merged",
      5,
      "planning",
      "ingest merged cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.split",
      0,
      "planning",
      "ingest split cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cursor.evicted",
      1,
      "resource",
      "ingest evicted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.accepted",
      3,
      "workflow",
      "ingest accepted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.started",
      4,
      "workflow",
      "ingest started payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.completed",
      5,
      "io",
      "ingest completed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.failed",
      0,
      "query",
      "ingest failed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.retried",
      1,
      "io",
      "ingest retried payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.skipped",
      2,
      "security",
      "ingest skipped payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.expired",
      3,
      "planning",
      "ingest expired payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.refreshed",
      4,
      "resource",
      "ingest refreshed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.rotated",
      5,
      "quality",
      "ingest rotated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.sealed",
      0,
      "quality",
      "ingest sealed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.opened",
      1,
      "resource",
      "ingest opened payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.closed",
      2,
      "consistency",
      "ingest closed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.validated",
      3,
      "io",
      "ingest validated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.rejected",
      4,
      "io",
      "ingest rejected payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.throttled",
      5,
      "planning",
      "ingest throttled payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.promoted",
      0,
      "planning",
      "ingest promoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.demoted",
      1,
      "planning",
      "ingest demoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.merged",
      2,
      "planning",
      "ingest merged payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.split",
      3,
      "planning",
      "ingest split payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "payload.evicted",
      4,
      "resource",
      "ingest evicted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.accepted",
      0,
      "workflow",
      "ingest accepted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.started",
      1,
      "workflow",
      "ingest started manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.completed",
      2,
      "io",
      "ingest completed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.failed",
      3,
      "query",
      "ingest failed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.retried",
      4,
      "io",
      "ingest retried manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.skipped",
      5,
      "security",
      "ingest skipped manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.expired",
      0,
      "planning",
      "ingest expired manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.refreshed",
      1,
      "resource",
      "ingest refreshed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.rotated",
      2,
      "quality",
      "ingest rotated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.sealed",
      3,
      "quality",
      "ingest sealed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.opened",
      4,
      "resource",
      "ingest opened manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.closed",
      5,
      "consistency",
      "ingest closed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.validated",
      0,
      "io",
      "ingest validated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.rejected",
      1,
      "io",
      "ingest rejected manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.throttled",
      2,
      "planning",
      "ingest throttled manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.promoted",
      3,
      "planning",
      "ingest promoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.demoted",
      4,
      "planning",
      "ingest demoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.merged",
      5,
      "planning",
      "ingest merged manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.split",
      0,
      "planning",
      "ingest split manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "manifest.evicted",
      1,
      "resource",
      "ingest evicted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.accepted",
      0,
      "workflow",
      "ingest accepted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.started",
      1,
      "workflow",
      "ingest started schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.completed",
      2,
      "io",
      "ingest completed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.failed",
      3,
      "query",
      "ingest failed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.retried",
      4,
      "io",
      "ingest retried schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.skipped",
      5,
      "security",
      "ingest skipped schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.expired",
      0,
      "planning",
      "ingest expired schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.refreshed",
      1,
      "resource",
      "ingest refreshed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.rotated",
      2,
      "quality",
      "ingest rotated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.sealed",
      3,
      "quality",
      "ingest sealed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.opened",
      4,
      "resource",
      "ingest opened schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.closed",
      5,
      "consistency",
      "ingest closed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.validated",
      0,
      "io",
      "ingest validated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.rejected",
      1,
      "io",
      "ingest rejected schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.throttled",
      2,
      "planning",
      "ingest throttled schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.promoted",
      3,
      "planning",
      "ingest promoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.demoted",
      4,
      "planning",
      "ingest demoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.merged",
      5,
      "planning",
      "ingest merged schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.split",
      0,
      "planning",
      "ingest split schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "schema.evicted",
      1,
      "resource",
      "ingest evicted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.accepted",
      3,
      "workflow",
      "ingest accepted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.started",
      4,
      "workflow",
      "ingest started session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.completed",
      5,
      "io",
      "ingest completed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.failed",
      0,
      "query",
      "ingest failed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.retried",
      1,
      "io",
      "ingest retried session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.skipped",
      2,
      "security",
      "ingest skipped session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.expired",
      3,
      "planning",
      "ingest expired session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.refreshed",
      4,
      "resource",
      "ingest refreshed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.rotated",
      5,
      "quality",
      "ingest rotated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.sealed",
      0,
      "quality",
      "ingest sealed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.opened",
      1,
      "resource",
      "ingest opened session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.closed",
      2,
      "consistency",
      "ingest closed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.validated",
      3,
      "io",
      "ingest validated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.rejected",
      4,
      "io",
      "ingest rejected session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.throttled",
      5,
      "planning",
      "ingest throttled session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.promoted",
      0,
      "planning",
      "ingest promoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.demoted",
      1,
      "planning",
      "ingest demoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.merged",
      2,
      "planning",
      "ingest merged session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.split",
      3,
      "planning",
      "ingest split session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "session.evicted",
      4,
      "resource",
      "ingest evicted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.accepted",
      4,
      "workflow",
      "ingest accepted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.started",
      5,
      "workflow",
      "ingest started window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.completed",
      0,
      "io",
      "ingest completed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.failed",
      1,
      "query",
      "ingest failed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.retried",
      2,
      "io",
      "ingest retried window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.skipped",
      3,
      "security",
      "ingest skipped window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.expired",
      4,
      "planning",
      "ingest expired window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.refreshed",
      5,
      "resource",
      "ingest refreshed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.rotated",
      0,
      "quality",
      "ingest rotated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.sealed",
      1,
      "quality",
      "ingest sealed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.opened",
      2,
      "resource",
      "ingest opened window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.closed",
      3,
      "consistency",
      "ingest closed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.validated",
      4,
      "io",
      "ingest validated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.rejected",
      5,
      "io",
      "ingest rejected window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.throttled",
      0,
      "planning",
      "ingest throttled window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.promoted",
      1,
      "planning",
      "ingest promoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.demoted",
      2,
      "planning",
      "ingest demoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.merged",
      3,
      "planning",
      "ingest merged window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.split",
      4,
      "planning",
      "ingest split window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "window.evicted",
      5,
      "resource",
      "ingest evicted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.accepted",
      5,
      "workflow",
      "ingest accepted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.started",
      0,
      "workflow",
      "ingest started index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.completed",
      1,
      "io",
      "ingest completed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.failed",
      2,
      "query",
      "ingest failed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.retried",
      3,
      "io",
      "ingest retried index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.skipped",
      4,
      "security",
      "ingest skipped index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.expired",
      5,
      "planning",
      "ingest expired index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.refreshed",
      0,
      "resource",
      "ingest refreshed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.rotated",
      1,
      "quality",
      "ingest rotated index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.sealed",
      2,
      "quality",
      "ingest sealed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.opened",
      3,
      "resource",
      "ingest opened index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.closed",
      4,
      "consistency",
      "ingest closed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.validated",
      5,
      "io",
      "ingest validated index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.rejected",
      0,
      "io",
      "ingest rejected index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.throttled",
      1,
      "planning",
      "ingest throttled index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.promoted",
      2,
      "planning",
      "ingest promoted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.demoted",
      3,
      "planning",
      "ingest demoted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.merged",
      4,
      "planning",
      "ingest merged index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.split",
      5,
      "planning",
      "ingest split index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "index.evicted",
      0,
      "resource",
      "ingest evicted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.accepted",
      5,
      "workflow",
      "ingest accepted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.started",
      0,
      "workflow",
      "ingest started cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.completed",
      1,
      "io",
      "ingest completed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.failed",
      2,
      "query",
      "ingest failed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.retried",
      3,
      "io",
      "ingest retried cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.skipped",
      4,
      "security",
      "ingest skipped cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.expired",
      5,
      "planning",
      "ingest expired cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.refreshed",
      0,
      "resource",
      "ingest refreshed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.rotated",
      1,
      "quality",
      "ingest rotated cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.sealed",
      2,
      "quality",
      "ingest sealed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.opened",
      3,
      "resource",
      "ingest opened cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.closed",
      4,
      "consistency",
      "ingest closed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.validated",
      5,
      "io",
      "ingest validated cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.rejected",
      0,
      "io",
      "ingest rejected cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.throttled",
      1,
      "planning",
      "ingest throttled cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.promoted",
      2,
      "planning",
      "ingest promoted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.demoted",
      3,
      "planning",
      "ingest demoted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.merged",
      4,
      "planning",
      "ingest merged cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.split",
      5,
      "planning",
      "ingest split cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "cacheline.evicted",
      0,
      "resource",
      "ingest evicted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.accepted",
      5,
      "workflow",
      "ingest accepted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.started",
      0,
      "workflow",
      "ingest started journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.completed",
      1,
      "io",
      "ingest completed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.failed",
      2,
      "query",
      "ingest failed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.retried",
      3,
      "io",
      "ingest retried journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.skipped",
      4,
      "security",
      "ingest skipped journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.expired",
      5,
      "planning",
      "ingest expired journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.refreshed",
      0,
      "resource",
      "ingest refreshed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.rotated",
      1,
      "quality",
      "ingest rotated journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.sealed",
      2,
      "quality",
      "ingest sealed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.opened",
      3,
      "resource",
      "ingest opened journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.closed",
      4,
      "consistency",
      "ingest closed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.validated",
      5,
      "io",
      "ingest validated journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.rejected",
      0,
      "io",
      "ingest rejected journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.throttled",
      1,
      "planning",
      "ingest throttled journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.promoted",
      2,
      "planning",
      "ingest promoted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.demoted",
      3,
      "planning",
      "ingest demoted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.merged",
      4,
      "planning",
      "ingest merged journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.split",
      5,
      "planning",
      "ingest split journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "journal.evicted",
      0,
      "resource",
      "ingest evicted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.accepted",
      2,
      "workflow",
      "ingest accepted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.started",
      3,
      "workflow",
      "ingest started snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.completed",
      4,
      "io",
      "ingest completed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.failed",
      5,
      "query",
      "ingest failed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.retried",
      0,
      "io",
      "ingest retried snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.skipped",
      1,
      "security",
      "ingest skipped snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.expired",
      2,
      "planning",
      "ingest expired snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.refreshed",
      3,
      "resource",
      "ingest refreshed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.rotated",
      4,
      "quality",
      "ingest rotated snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.sealed",
      5,
      "quality",
      "ingest sealed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.opened",
      0,
      "resource",
      "ingest opened snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.closed",
      1,
      "consistency",
      "ingest closed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.validated",
      2,
      "io",
      "ingest validated snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.rejected",
      3,
      "io",
      "ingest rejected snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.throttled",
      4,
      "planning",
      "ingest throttled snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.promoted",
      5,
      "planning",
      "ingest promoted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.demoted",
      0,
      "planning",
      "ingest demoted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.merged",
      1,
      "planning",
      "ingest merged snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.split",
      2,
      "planning",
      "ingest split snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "snapshot.evicted",
      3,
      "resource",
      "ingest evicted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.accepted",
      2,
      "workflow",
      "ingest accepted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.started",
      3,
      "workflow",
      "ingest started bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.completed",
      4,
      "io",
      "ingest completed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.failed",
      5,
      "query",
      "ingest failed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.retried",
      0,
      "io",
      "ingest retried bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.skipped",
      1,
      "security",
      "ingest skipped bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.expired",
      2,
      "planning",
      "ingest expired bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.refreshed",
      3,
      "resource",
      "ingest refreshed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.rotated",
      4,
      "quality",
      "ingest rotated bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.sealed",
      5,
      "quality",
      "ingest sealed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.opened",
      0,
      "resource",
      "ingest opened bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.closed",
      1,
      "consistency",
      "ingest closed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.validated",
      2,
      "io",
      "ingest validated bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.rejected",
      3,
      "io",
      "ingest rejected bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.throttled",
      4,
      "planning",
      "ingest throttled bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.promoted",
      5,
      "planning",
      "ingest promoted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.demoted",
      0,
      "planning",
      "ingest demoted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.merged",
      1,
      "planning",
      "ingest merged bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.split",
      2,
      "planning",
      "ingest split bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "bundle.evicted",
      3,
      "resource",
      "ingest evicted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.accepted",
      5,
      "workflow",
      "ingest accepted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.started",
      0,
      "workflow",
      "ingest started catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.completed",
      1,
      "io",
      "ingest completed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.failed",
      2,
      "query",
      "ingest failed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.retried",
      3,
      "io",
      "ingest retried catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.skipped",
      4,
      "security",
      "ingest skipped catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.expired",
      5,
      "planning",
      "ingest expired catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.refreshed",
      0,
      "resource",
      "ingest refreshed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.rotated",
      1,
      "quality",
      "ingest rotated catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.sealed",
      2,
      "quality",
      "ingest sealed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.opened",
      3,
      "resource",
      "ingest opened catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.closed",
      4,
      "consistency",
      "ingest closed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.validated",
      5,
      "io",
      "ingest validated catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.rejected",
      0,
      "io",
      "ingest rejected catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.throttled",
      1,
      "planning",
      "ingest throttled catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.promoted",
      2,
      "planning",
      "ingest promoted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.demoted",
      3,
      "planning",
      "ingest demoted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.merged",
      4,
      "planning",
      "ingest merged catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.split",
      5,
      "planning",
      "ingest split catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "catalog.evicted",
      0,
      "resource",
      "ingest evicted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.accepted",
      3,
      "workflow",
      "ingest accepted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.started",
      4,
      "workflow",
      "ingest started partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.completed",
      5,
      "io",
      "ingest completed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.failed",
      0,
      "query",
      "ingest failed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.retried",
      1,
      "io",
      "ingest retried partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.skipped",
      2,
      "security",
      "ingest skipped partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.expired",
      3,
      "planning",
      "ingest expired partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.refreshed",
      4,
      "resource",
      "ingest refreshed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.rotated",
      5,
      "quality",
      "ingest rotated partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.sealed",
      0,
      "quality",
      "ingest sealed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.opened",
      1,
      "resource",
      "ingest opened partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.closed",
      2,
      "consistency",
      "ingest closed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.validated",
      3,
      "io",
      "ingest validated partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.rejected",
      4,
      "io",
      "ingest rejected partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.throttled",
      5,
      "planning",
      "ingest throttled partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.promoted",
      0,
      "planning",
      "ingest promoted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.demoted",
      1,
      "planning",
      "ingest demoted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.merged",
      2,
      "planning",
      "ingest merged partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.split",
      3,
      "planning",
      "ingest split partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "partition.evicted",
      4,
      "resource",
      "ingest evicted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.accepted",
      1,
      "workflow",
      "ingest accepted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.started",
      2,
      "workflow",
      "ingest started query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.completed",
      3,
      "io",
      "ingest completed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.failed",
      4,
      "query",
      "ingest failed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.retried",
      5,
      "io",
      "ingest retried query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.skipped",
      0,
      "security",
      "ingest skipped query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.expired",
      1,
      "planning",
      "ingest expired query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.refreshed",
      2,
      "resource",
      "ingest refreshed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.rotated",
      3,
      "quality",
      "ingest rotated query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.sealed",
      4,
      "quality",
      "ingest sealed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.opened",
      5,
      "resource",
      "ingest opened query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.closed",
      0,
      "consistency",
      "ingest closed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.validated",
      1,
      "io",
      "ingest validated query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.rejected",
      2,
      "io",
      "ingest rejected query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.throttled",
      3,
      "planning",
      "ingest throttled query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.promoted",
      4,
      "planning",
      "ingest promoted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.demoted",
      5,
      "planning",
      "ingest demoted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.merged",
      0,
      "planning",
      "ingest merged query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.split",
      1,
      "planning",
      "ingest split query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "ingest",
      "query.evicted",
      2,
      "resource",
      "ingest evicted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.accepted",
      3,
      "workflow",
      "worker accepted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.started",
      4,
      "workflow",
      "worker started batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.completed",
      5,
      "io",
      "worker completed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.failed",
      0,
      "query",
      "worker failed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.retried",
      1,
      "io",
      "worker retried batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.skipped",
      2,
      "security",
      "worker skipped batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.expired",
      3,
      "planning",
      "worker expired batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.refreshed",
      4,
      "resource",
      "worker refreshed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.rotated",
      5,
      "quality",
      "worker rotated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.sealed",
      0,
      "quality",
      "worker sealed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.opened",
      1,
      "resource",
      "worker opened batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.closed",
      2,
      "consistency",
      "worker closed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.validated",
      3,
      "io",
      "worker validated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.rejected",
      4,
      "io",
      "worker rejected batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.throttled",
      5,
      "planning",
      "worker throttled batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.promoted",
      0,
      "planning",
      "worker promoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.demoted",
      1,
      "planning",
      "worker demoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.merged",
      2,
      "planning",
      "worker merged batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.split",
      3,
      "planning",
      "worker split batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "batch.evicted",
      4,
      "resource",
      "worker evicted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.accepted",
      1,
      "workflow",
      "worker accepted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.started",
      2,
      "workflow",
      "worker started segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.completed",
      3,
      "io",
      "worker completed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.failed",
      4,
      "query",
      "worker failed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.retried",
      5,
      "io",
      "worker retried segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.skipped",
      0,
      "security",
      "worker skipped segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.expired",
      1,
      "planning",
      "worker expired segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.refreshed",
      2,
      "resource",
      "worker refreshed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.rotated",
      3,
      "quality",
      "worker rotated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.sealed",
      4,
      "quality",
      "worker sealed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.opened",
      5,
      "resource",
      "worker opened segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.closed",
      0,
      "consistency",
      "worker closed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.validated",
      1,
      "io",
      "worker validated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.rejected",
      2,
      "io",
      "worker rejected segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.throttled",
      3,
      "planning",
      "worker throttled segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.promoted",
      4,
      "planning",
      "worker promoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.demoted",
      5,
      "planning",
      "worker demoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.merged",
      0,
      "planning",
      "worker merged segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.split",
      1,
      "planning",
      "worker split segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "segment.evicted",
      2,
      "resource",
      "worker evicted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.accepted",
      0,
      "workflow",
      "worker accepted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.started",
      1,
      "workflow",
      "worker started checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.completed",
      2,
      "io",
      "worker completed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.failed",
      3,
      "query",
      "worker failed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.retried",
      4,
      "io",
      "worker retried checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.skipped",
      5,
      "security",
      "worker skipped checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.expired",
      0,
      "planning",
      "worker expired checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.refreshed",
      1,
      "resource",
      "worker refreshed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.rotated",
      2,
      "quality",
      "worker rotated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.sealed",
      3,
      "quality",
      "worker sealed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.opened",
      4,
      "resource",
      "worker opened checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.closed",
      5,
      "consistency",
      "worker closed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.validated",
      0,
      "io",
      "worker validated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.rejected",
      1,
      "io",
      "worker rejected checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.throttled",
      2,
      "planning",
      "worker throttled checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.promoted",
      3,
      "planning",
      "worker promoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.demoted",
      4,
      "planning",
      "worker demoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.merged",
      5,
      "planning",
      "worker merged checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.split",
      0,
      "planning",
      "worker split checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "checkpoint.evicted",
      1,
      "resource",
      "worker evicted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.accepted",
      3,
      "workflow",
      "worker accepted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.started",
      4,
      "workflow",
      "worker started lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.completed",
      5,
      "io",
      "worker completed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.failed",
      0,
      "query",
      "worker failed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.retried",
      1,
      "io",
      "worker retried lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.skipped",
      2,
      "security",
      "worker skipped lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.expired",
      3,
      "planning",
      "worker expired lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.refreshed",
      4,
      "resource",
      "worker refreshed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.rotated",
      5,
      "quality",
      "worker rotated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.sealed",
      0,
      "quality",
      "worker sealed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.opened",
      1,
      "resource",
      "worker opened lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.closed",
      2,
      "consistency",
      "worker closed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.validated",
      3,
      "io",
      "worker validated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.rejected",
      4,
      "io",
      "worker rejected lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.throttled",
      5,
      "planning",
      "worker throttled lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.promoted",
      0,
      "planning",
      "worker promoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.demoted",
      1,
      "planning",
      "worker demoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.merged",
      2,
      "planning",
      "worker merged lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.split",
      3,
      "planning",
      "worker split lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "lease.evicted",
      4,
      "resource",
      "worker evicted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.accepted",
      5,
      "workflow",
      "worker accepted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.started",
      0,
      "workflow",
      "worker started token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.completed",
      1,
      "io",
      "worker completed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.failed",
      2,
      "query",
      "worker failed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.retried",
      3,
      "io",
      "worker retried token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.skipped",
      4,
      "security",
      "worker skipped token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.expired",
      5,
      "planning",
      "worker expired token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.refreshed",
      0,
      "resource",
      "worker refreshed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.rotated",
      1,
      "quality",
      "worker rotated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.sealed",
      2,
      "quality",
      "worker sealed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.opened",
      3,
      "resource",
      "worker opened token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.closed",
      4,
      "consistency",
      "worker closed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.validated",
      5,
      "io",
      "worker validated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.rejected",
      0,
      "io",
      "worker rejected token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.throttled",
      1,
      "planning",
      "worker throttled token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.promoted",
      2,
      "planning",
      "worker promoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.demoted",
      3,
      "planning",
      "worker demoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.merged",
      4,
      "planning",
      "worker merged token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.split",
      5,
      "planning",
      "worker split token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "token.evicted",
      0,
      "resource",
      "worker evicted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.accepted",
      2,
      "workflow",
      "worker accepted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.started",
      3,
      "workflow",
      "worker started stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.completed",
      4,
      "io",
      "worker completed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.failed",
      5,
      "query",
      "worker failed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.retried",
      0,
      "io",
      "worker retried stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.skipped",
      1,
      "security",
      "worker skipped stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.expired",
      2,
      "planning",
      "worker expired stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.refreshed",
      3,
      "resource",
      "worker refreshed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.rotated",
      4,
      "quality",
      "worker rotated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.sealed",
      5,
      "quality",
      "worker sealed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.opened",
      0,
      "resource",
      "worker opened stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.closed",
      1,
      "consistency",
      "worker closed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.validated",
      2,
      "io",
      "worker validated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.rejected",
      3,
      "io",
      "worker rejected stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.throttled",
      4,
      "planning",
      "worker throttled stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.promoted",
      5,
      "planning",
      "worker promoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.demoted",
      0,
      "planning",
      "worker demoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.merged",
      1,
      "planning",
      "worker merged stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.split",
      2,
      "planning",
      "worker split stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "stream.evicted",
      3,
      "resource",
      "worker evicted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.accepted",
      4,
      "workflow",
      "worker accepted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.started",
      5,
      "workflow",
      "worker started cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.completed",
      0,
      "io",
      "worker completed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.failed",
      1,
      "query",
      "worker failed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.retried",
      2,
      "io",
      "worker retried cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.skipped",
      3,
      "security",
      "worker skipped cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.expired",
      4,
      "planning",
      "worker expired cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.refreshed",
      5,
      "resource",
      "worker refreshed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.rotated",
      0,
      "quality",
      "worker rotated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.sealed",
      1,
      "quality",
      "worker sealed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.opened",
      2,
      "resource",
      "worker opened cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.closed",
      3,
      "consistency",
      "worker closed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.validated",
      4,
      "io",
      "worker validated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.rejected",
      5,
      "io",
      "worker rejected cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.throttled",
      0,
      "planning",
      "worker throttled cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.promoted",
      1,
      "planning",
      "worker promoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.demoted",
      2,
      "planning",
      "worker demoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.merged",
      3,
      "planning",
      "worker merged cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.split",
      4,
      "planning",
      "worker split cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cursor.evicted",
      5,
      "resource",
      "worker evicted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.accepted",
      1,
      "workflow",
      "worker accepted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.started",
      2,
      "workflow",
      "worker started payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.completed",
      3,
      "io",
      "worker completed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.failed",
      4,
      "query",
      "worker failed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.retried",
      5,
      "io",
      "worker retried payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.skipped",
      0,
      "security",
      "worker skipped payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.expired",
      1,
      "planning",
      "worker expired payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.refreshed",
      2,
      "resource",
      "worker refreshed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.rotated",
      3,
      "quality",
      "worker rotated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.sealed",
      4,
      "quality",
      "worker sealed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.opened",
      5,
      "resource",
      "worker opened payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.closed",
      0,
      "consistency",
      "worker closed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.validated",
      1,
      "io",
      "worker validated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.rejected",
      2,
      "io",
      "worker rejected payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.throttled",
      3,
      "planning",
      "worker throttled payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.promoted",
      4,
      "planning",
      "worker promoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.demoted",
      5,
      "planning",
      "worker demoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.merged",
      0,
      "planning",
      "worker merged payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.split",
      1,
      "planning",
      "worker split payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "payload.evicted",
      2,
      "resource",
      "worker evicted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.accepted",
      4,
      "workflow",
      "worker accepted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.started",
      5,
      "workflow",
      "worker started manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.completed",
      0,
      "io",
      "worker completed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.failed",
      1,
      "query",
      "worker failed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.retried",
      2,
      "io",
      "worker retried manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.skipped",
      3,
      "security",
      "worker skipped manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.expired",
      4,
      "planning",
      "worker expired manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.refreshed",
      5,
      "resource",
      "worker refreshed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.rotated",
      0,
      "quality",
      "worker rotated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.sealed",
      1,
      "quality",
      "worker sealed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.opened",
      2,
      "resource",
      "worker opened manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.closed",
      3,
      "consistency",
      "worker closed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.validated",
      4,
      "io",
      "worker validated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.rejected",
      5,
      "io",
      "worker rejected manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.throttled",
      0,
      "planning",
      "worker throttled manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.promoted",
      1,
      "planning",
      "worker promoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.demoted",
      2,
      "planning",
      "worker demoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.merged",
      3,
      "planning",
      "worker merged manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.split",
      4,
      "planning",
      "worker split manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "manifest.evicted",
      5,
      "resource",
      "worker evicted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.accepted",
      4,
      "workflow",
      "worker accepted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.started",
      5,
      "workflow",
      "worker started schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.completed",
      0,
      "io",
      "worker completed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.failed",
      1,
      "query",
      "worker failed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.retried",
      2,
      "io",
      "worker retried schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.skipped",
      3,
      "security",
      "worker skipped schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.expired",
      4,
      "planning",
      "worker expired schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.refreshed",
      5,
      "resource",
      "worker refreshed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.rotated",
      0,
      "quality",
      "worker rotated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.sealed",
      1,
      "quality",
      "worker sealed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.opened",
      2,
      "resource",
      "worker opened schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.closed",
      3,
      "consistency",
      "worker closed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.validated",
      4,
      "io",
      "worker validated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.rejected",
      5,
      "io",
      "worker rejected schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.throttled",
      0,
      "planning",
      "worker throttled schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.promoted",
      1,
      "planning",
      "worker promoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.demoted",
      2,
      "planning",
      "worker demoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.merged",
      3,
      "planning",
      "worker merged schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.split",
      4,
      "planning",
      "worker split schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "schema.evicted",
      5,
      "resource",
      "worker evicted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.accepted",
      1,
      "workflow",
      "worker accepted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.started",
      2,
      "workflow",
      "worker started session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.completed",
      3,
      "io",
      "worker completed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.failed",
      4,
      "query",
      "worker failed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.retried",
      5,
      "io",
      "worker retried session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.skipped",
      0,
      "security",
      "worker skipped session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.expired",
      1,
      "planning",
      "worker expired session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.refreshed",
      2,
      "resource",
      "worker refreshed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.rotated",
      3,
      "quality",
      "worker rotated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.sealed",
      4,
      "quality",
      "worker sealed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.opened",
      5,
      "resource",
      "worker opened session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.closed",
      0,
      "consistency",
      "worker closed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.validated",
      1,
      "io",
      "worker validated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.rejected",
      2,
      "io",
      "worker rejected session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.throttled",
      3,
      "planning",
      "worker throttled session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.promoted",
      4,
      "planning",
      "worker promoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.demoted",
      5,
      "planning",
      "worker demoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.merged",
      0,
      "planning",
      "worker merged session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.split",
      1,
      "planning",
      "worker split session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "session.evicted",
      2,
      "resource",
      "worker evicted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.accepted",
      2,
      "workflow",
      "worker accepted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.started",
      3,
      "workflow",
      "worker started window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.completed",
      4,
      "io",
      "worker completed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.failed",
      5,
      "query",
      "worker failed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.retried",
      0,
      "io",
      "worker retried window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.skipped",
      1,
      "security",
      "worker skipped window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.expired",
      2,
      "planning",
      "worker expired window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.refreshed",
      3,
      "resource",
      "worker refreshed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.rotated",
      4,
      "quality",
      "worker rotated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.sealed",
      5,
      "quality",
      "worker sealed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.opened",
      0,
      "resource",
      "worker opened window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.closed",
      1,
      "consistency",
      "worker closed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.validated",
      2,
      "io",
      "worker validated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.rejected",
      3,
      "io",
      "worker rejected window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.throttled",
      4,
      "planning",
      "worker throttled window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.promoted",
      5,
      "planning",
      "worker promoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.demoted",
      0,
      "planning",
      "worker demoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.merged",
      1,
      "planning",
      "worker merged window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.split",
      2,
      "planning",
      "worker split window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "window.evicted",
      3,
      "resource",
      "worker evicted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.accepted",
      3,
      "workflow",
      "worker accepted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.started",
      4,
      "workflow",
      "worker started index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.completed",
      5,
      "io",
      "worker completed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.failed",
      0,
      "query",
      "worker failed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.retried",
      1,
      "io",
      "worker retried index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.skipped",
      2,
      "security",
      "worker skipped index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.expired",
      3,
      "planning",
      "worker expired index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.refreshed",
      4,
      "resource",
      "worker refreshed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.rotated",
      5,
      "quality",
      "worker rotated index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.sealed",
      0,
      "quality",
      "worker sealed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.opened",
      1,
      "resource",
      "worker opened index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.closed",
      2,
      "consistency",
      "worker closed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.validated",
      3,
      "io",
      "worker validated index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.rejected",
      4,
      "io",
      "worker rejected index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.throttled",
      5,
      "planning",
      "worker throttled index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.promoted",
      0,
      "planning",
      "worker promoted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.demoted",
      1,
      "planning",
      "worker demoted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.merged",
      2,
      "planning",
      "worker merged index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.split",
      3,
      "planning",
      "worker split index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "index.evicted",
      4,
      "resource",
      "worker evicted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.accepted",
      3,
      "workflow",
      "worker accepted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.started",
      4,
      "workflow",
      "worker started cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.completed",
      5,
      "io",
      "worker completed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.failed",
      0,
      "query",
      "worker failed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.retried",
      1,
      "io",
      "worker retried cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.skipped",
      2,
      "security",
      "worker skipped cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.expired",
      3,
      "planning",
      "worker expired cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.refreshed",
      4,
      "resource",
      "worker refreshed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.rotated",
      5,
      "quality",
      "worker rotated cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.sealed",
      0,
      "quality",
      "worker sealed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.opened",
      1,
      "resource",
      "worker opened cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.closed",
      2,
      "consistency",
      "worker closed cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.validated",
      3,
      "io",
      "worker validated cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.rejected",
      4,
      "io",
      "worker rejected cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.throttled",
      5,
      "planning",
      "worker throttled cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.promoted",
      0,
      "planning",
      "worker promoted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.demoted",
      1,
      "planning",
      "worker demoted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.merged",
      2,
      "planning",
      "worker merged cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.split",
      3,
      "planning",
      "worker split cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "cacheline.evicted",
      4,
      "resource",
      "worker evicted cacheline event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.accepted",
      3,
      "workflow",
      "worker accepted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.started",
      4,
      "workflow",
      "worker started journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.completed",
      5,
      "io",
      "worker completed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.failed",
      0,
      "query",
      "worker failed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.retried",
      1,
      "io",
      "worker retried journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.skipped",
      2,
      "security",
      "worker skipped journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.expired",
      3,
      "planning",
      "worker expired journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.refreshed",
      4,
      "resource",
      "worker refreshed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.rotated",
      5,
      "quality",
      "worker rotated journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.sealed",
      0,
      "quality",
      "worker sealed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.opened",
      1,
      "resource",
      "worker opened journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.closed",
      2,
      "consistency",
      "worker closed journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.validated",
      3,
      "io",
      "worker validated journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.rejected",
      4,
      "io",
      "worker rejected journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.throttled",
      5,
      "planning",
      "worker throttled journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.promoted",
      0,
      "planning",
      "worker promoted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.demoted",
      1,
      "planning",
      "worker demoted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.merged",
      2,
      "planning",
      "worker merged journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.split",
      3,
      "planning",
      "worker split journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "journal.evicted",
      4,
      "resource",
      "worker evicted journal event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.accepted",
      0,
      "workflow",
      "worker accepted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.started",
      1,
      "workflow",
      "worker started snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.completed",
      2,
      "io",
      "worker completed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.failed",
      3,
      "query",
      "worker failed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.retried",
      4,
      "io",
      "worker retried snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.skipped",
      5,
      "security",
      "worker skipped snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.expired",
      0,
      "planning",
      "worker expired snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.refreshed",
      1,
      "resource",
      "worker refreshed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.rotated",
      2,
      "quality",
      "worker rotated snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.sealed",
      3,
      "quality",
      "worker sealed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.opened",
      4,
      "resource",
      "worker opened snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.closed",
      5,
      "consistency",
      "worker closed snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.validated",
      0,
      "io",
      "worker validated snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.rejected",
      1,
      "io",
      "worker rejected snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.throttled",
      2,
      "planning",
      "worker throttled snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.promoted",
      3,
      "planning",
      "worker promoted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.demoted",
      4,
      "planning",
      "worker demoted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.merged",
      5,
      "planning",
      "worker merged snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.split",
      0,
      "planning",
      "worker split snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "snapshot.evicted",
      1,
      "resource",
      "worker evicted snapshot event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.accepted",
      0,
      "workflow",
      "worker accepted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.started",
      1,
      "workflow",
      "worker started bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.completed",
      2,
      "io",
      "worker completed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.failed",
      3,
      "query",
      "worker failed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.retried",
      4,
      "io",
      "worker retried bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.skipped",
      5,
      "security",
      "worker skipped bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.expired",
      0,
      "planning",
      "worker expired bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.refreshed",
      1,
      "resource",
      "worker refreshed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.rotated",
      2,
      "quality",
      "worker rotated bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.sealed",
      3,
      "quality",
      "worker sealed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.opened",
      4,
      "resource",
      "worker opened bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.closed",
      5,
      "consistency",
      "worker closed bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.validated",
      0,
      "io",
      "worker validated bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.rejected",
      1,
      "io",
      "worker rejected bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.throttled",
      2,
      "planning",
      "worker throttled bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.promoted",
      3,
      "planning",
      "worker promoted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.demoted",
      4,
      "planning",
      "worker demoted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.merged",
      5,
      "planning",
      "worker merged bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.split",
      0,
      "planning",
      "worker split bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "bundle.evicted",
      1,
      "resource",
      "worker evicted bundle event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.accepted",
      3,
      "workflow",
      "worker accepted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.started",
      4,
      "workflow",
      "worker started catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.completed",
      5,
      "io",
      "worker completed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.failed",
      0,
      "query",
      "worker failed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.retried",
      1,
      "io",
      "worker retried catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.skipped",
      2,
      "security",
      "worker skipped catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.expired",
      3,
      "planning",
      "worker expired catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.refreshed",
      4,
      "resource",
      "worker refreshed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.rotated",
      5,
      "quality",
      "worker rotated catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.sealed",
      0,
      "quality",
      "worker sealed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.opened",
      1,
      "resource",
      "worker opened catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.closed",
      2,
      "consistency",
      "worker closed catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.validated",
      3,
      "io",
      "worker validated catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.rejected",
      4,
      "io",
      "worker rejected catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.throttled",
      5,
      "planning",
      "worker throttled catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.promoted",
      0,
      "planning",
      "worker promoted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.demoted",
      1,
      "planning",
      "worker demoted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.merged",
      2,
      "planning",
      "worker merged catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.split",
      3,
      "planning",
      "worker split catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "catalog.evicted",
      4,
      "resource",
      "worker evicted catalog event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.accepted",
      1,
      "workflow",
      "worker accepted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.started",
      2,
      "workflow",
      "worker started partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.completed",
      3,
      "io",
      "worker completed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.failed",
      4,
      "query",
      "worker failed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.retried",
      5,
      "io",
      "worker retried partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.skipped",
      0,
      "security",
      "worker skipped partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.expired",
      1,
      "planning",
      "worker expired partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.refreshed",
      2,
      "resource",
      "worker refreshed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.rotated",
      3,
      "quality",
      "worker rotated partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.sealed",
      4,
      "quality",
      "worker sealed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.opened",
      5,
      "resource",
      "worker opened partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.closed",
      0,
      "consistency",
      "worker closed partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.validated",
      1,
      "io",
      "worker validated partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.rejected",
      2,
      "io",
      "worker rejected partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.throttled",
      3,
      "planning",
      "worker throttled partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.promoted",
      4,
      "planning",
      "worker promoted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.demoted",
      5,
      "planning",
      "worker demoted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.merged",
      0,
      "planning",
      "worker merged partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.split",
      1,
      "planning",
      "worker split partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "partition.evicted",
      2,
      "resource",
      "worker evicted partition event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.accepted",
      5,
      "workflow",
      "worker accepted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.started",
      0,
      "workflow",
      "worker started query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.completed",
      1,
      "io",
      "worker completed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.failed",
      2,
      "query",
      "worker failed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.retried",
      3,
      "io",
      "worker retried query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.skipped",
      4,
      "security",
      "worker skipped query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.expired",
      5,
      "planning",
      "worker expired query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.refreshed",
      0,
      "resource",
      "worker refreshed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.rotated",
      1,
      "quality",
      "worker rotated query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.sealed",
      2,
      "quality",
      "worker sealed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.opened",
      3,
      "resource",
      "worker opened query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.closed",
      4,
      "consistency",
      "worker closed query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.validated",
      5,
      "io",
      "worker validated query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.rejected",
      0,
      "io",
      "worker rejected query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.throttled",
      1,
      "planning",
      "worker throttled query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.promoted",
      2,
      "planning",
      "worker promoted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.demoted",
      3,
      "planning",
      "worker demoted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.merged",
      4,
      "planning",
      "worker merged query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.split",
      5,
      "planning",
      "worker split query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "worker",
      "query.evicted",
      0,
      "resource",
      "worker evicted query event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.accepted",
      4,
      "workflow",
      "scheduler accepted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.started",
      5,
      "workflow",
      "scheduler started batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.completed",
      0,
      "io",
      "scheduler completed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.failed",
      1,
      "query",
      "scheduler failed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.retried",
      2,
      "io",
      "scheduler retried batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.skipped",
      3,
      "security",
      "scheduler skipped batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.expired",
      4,
      "planning",
      "scheduler expired batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.refreshed",
      5,
      "resource",
      "scheduler refreshed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.rotated",
      0,
      "quality",
      "scheduler rotated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.sealed",
      1,
      "quality",
      "scheduler sealed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.opened",
      2,
      "resource",
      "scheduler opened batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.closed",
      3,
      "consistency",
      "scheduler closed batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.validated",
      4,
      "io",
      "scheduler validated batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.rejected",
      5,
      "io",
      "scheduler rejected batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.throttled",
      0,
      "planning",
      "scheduler throttled batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.promoted",
      1,
      "planning",
      "scheduler promoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.demoted",
      2,
      "planning",
      "scheduler demoted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.merged",
      3,
      "planning",
      "scheduler merged batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.split",
      4,
      "planning",
      "scheduler split batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "batch.evicted",
      5,
      "resource",
      "scheduler evicted batch event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.accepted",
      2,
      "workflow",
      "scheduler accepted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.started",
      3,
      "workflow",
      "scheduler started segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.completed",
      4,
      "io",
      "scheduler completed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.failed",
      5,
      "query",
      "scheduler failed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.retried",
      0,
      "io",
      "scheduler retried segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.skipped",
      1,
      "security",
      "scheduler skipped segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.expired",
      2,
      "planning",
      "scheduler expired segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.refreshed",
      3,
      "resource",
      "scheduler refreshed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.rotated",
      4,
      "quality",
      "scheduler rotated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.sealed",
      5,
      "quality",
      "scheduler sealed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.opened",
      0,
      "resource",
      "scheduler opened segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.closed",
      1,
      "consistency",
      "scheduler closed segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.validated",
      2,
      "io",
      "scheduler validated segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.rejected",
      3,
      "io",
      "scheduler rejected segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.throttled",
      4,
      "planning",
      "scheduler throttled segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.promoted",
      5,
      "planning",
      "scheduler promoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.demoted",
      0,
      "planning",
      "scheduler demoted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.merged",
      1,
      "planning",
      "scheduler merged segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.split",
      2,
      "planning",
      "scheduler split segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "segment.evicted",
      3,
      "resource",
      "scheduler evicted segment event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.accepted",
      1,
      "workflow",
      "scheduler accepted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.started",
      2,
      "workflow",
      "scheduler started checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.completed",
      3,
      "io",
      "scheduler completed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.failed",
      4,
      "query",
      "scheduler failed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.retried",
      5,
      "io",
      "scheduler retried checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.skipped",
      0,
      "security",
      "scheduler skipped checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.expired",
      1,
      "planning",
      "scheduler expired checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.refreshed",
      2,
      "resource",
      "scheduler refreshed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.rotated",
      3,
      "quality",
      "scheduler rotated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.sealed",
      4,
      "quality",
      "scheduler sealed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.opened",
      5,
      "resource",
      "scheduler opened checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.closed",
      0,
      "consistency",
      "scheduler closed checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.validated",
      1,
      "io",
      "scheduler validated checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.rejected",
      2,
      "io",
      "scheduler rejected checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.throttled",
      3,
      "planning",
      "scheduler throttled checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.promoted",
      4,
      "planning",
      "scheduler promoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.demoted",
      5,
      "planning",
      "scheduler demoted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.merged",
      0,
      "planning",
      "scheduler merged checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.split",
      1,
      "planning",
      "scheduler split checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "checkpoint.evicted",
      2,
      "resource",
      "scheduler evicted checkpoint event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.accepted",
      4,
      "workflow",
      "scheduler accepted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.started",
      5,
      "workflow",
      "scheduler started lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.completed",
      0,
      "io",
      "scheduler completed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.failed",
      1,
      "query",
      "scheduler failed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.retried",
      2,
      "io",
      "scheduler retried lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.skipped",
      3,
      "security",
      "scheduler skipped lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.expired",
      4,
      "planning",
      "scheduler expired lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.refreshed",
      5,
      "resource",
      "scheduler refreshed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.rotated",
      0,
      "quality",
      "scheduler rotated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.sealed",
      1,
      "quality",
      "scheduler sealed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.opened",
      2,
      "resource",
      "scheduler opened lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.closed",
      3,
      "consistency",
      "scheduler closed lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.validated",
      4,
      "io",
      "scheduler validated lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.rejected",
      5,
      "io",
      "scheduler rejected lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.throttled",
      0,
      "planning",
      "scheduler throttled lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.promoted",
      1,
      "planning",
      "scheduler promoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.demoted",
      2,
      "planning",
      "scheduler demoted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.merged",
      3,
      "planning",
      "scheduler merged lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.split",
      4,
      "planning",
      "scheduler split lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "lease.evicted",
      5,
      "resource",
      "scheduler evicted lease event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.accepted",
      0,
      "workflow",
      "scheduler accepted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.started",
      1,
      "workflow",
      "scheduler started token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.completed",
      2,
      "io",
      "scheduler completed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.failed",
      3,
      "query",
      "scheduler failed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.retried",
      4,
      "io",
      "scheduler retried token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.skipped",
      5,
      "security",
      "scheduler skipped token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.expired",
      0,
      "planning",
      "scheduler expired token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.refreshed",
      1,
      "resource",
      "scheduler refreshed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.rotated",
      2,
      "quality",
      "scheduler rotated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.sealed",
      3,
      "quality",
      "scheduler sealed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.opened",
      4,
      "resource",
      "scheduler opened token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.closed",
      5,
      "consistency",
      "scheduler closed token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.validated",
      0,
      "io",
      "scheduler validated token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.rejected",
      1,
      "io",
      "scheduler rejected token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.throttled",
      2,
      "planning",
      "scheduler throttled token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.promoted",
      3,
      "planning",
      "scheduler promoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.demoted",
      4,
      "planning",
      "scheduler demoted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.merged",
      5,
      "planning",
      "scheduler merged token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.split",
      0,
      "planning",
      "scheduler split token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "token.evicted",
      1,
      "resource",
      "scheduler evicted token event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.accepted",
      3,
      "workflow",
      "scheduler accepted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.started",
      4,
      "workflow",
      "scheduler started stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.completed",
      5,
      "io",
      "scheduler completed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.failed",
      0,
      "query",
      "scheduler failed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.retried",
      1,
      "io",
      "scheduler retried stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.skipped",
      2,
      "security",
      "scheduler skipped stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.expired",
      3,
      "planning",
      "scheduler expired stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.refreshed",
      4,
      "resource",
      "scheduler refreshed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.rotated",
      5,
      "quality",
      "scheduler rotated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.sealed",
      0,
      "quality",
      "scheduler sealed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.opened",
      1,
      "resource",
      "scheduler opened stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.closed",
      2,
      "consistency",
      "scheduler closed stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.validated",
      3,
      "io",
      "scheduler validated stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.rejected",
      4,
      "io",
      "scheduler rejected stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.throttled",
      5,
      "planning",
      "scheduler throttled stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.promoted",
      0,
      "planning",
      "scheduler promoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.demoted",
      1,
      "planning",
      "scheduler demoted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.merged",
      2,
      "planning",
      "scheduler merged stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.split",
      3,
      "planning",
      "scheduler split stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "stream.evicted",
      4,
      "resource",
      "scheduler evicted stream event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.accepted",
      5,
      "workflow",
      "scheduler accepted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.started",
      0,
      "workflow",
      "scheduler started cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.completed",
      1,
      "io",
      "scheduler completed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.failed",
      2,
      "query",
      "scheduler failed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.retried",
      3,
      "io",
      "scheduler retried cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.skipped",
      4,
      "security",
      "scheduler skipped cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.expired",
      5,
      "planning",
      "scheduler expired cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.refreshed",
      0,
      "resource",
      "scheduler refreshed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.rotated",
      1,
      "quality",
      "scheduler rotated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.sealed",
      2,
      "quality",
      "scheduler sealed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.opened",
      3,
      "resource",
      "scheduler opened cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.closed",
      4,
      "consistency",
      "scheduler closed cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.validated",
      5,
      "io",
      "scheduler validated cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.rejected",
      0,
      "io",
      "scheduler rejected cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.throttled",
      1,
      "planning",
      "scheduler throttled cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.promoted",
      2,
      "planning",
      "scheduler promoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.demoted",
      3,
      "planning",
      "scheduler demoted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.merged",
      4,
      "planning",
      "scheduler merged cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.split",
      5,
      "planning",
      "scheduler split cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "cursor.evicted",
      0,
      "resource",
      "scheduler evicted cursor event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.accepted",
      2,
      "workflow",
      "scheduler accepted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.started",
      3,
      "workflow",
      "scheduler started payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.completed",
      4,
      "io",
      "scheduler completed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.failed",
      5,
      "query",
      "scheduler failed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.retried",
      0,
      "io",
      "scheduler retried payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.skipped",
      1,
      "security",
      "scheduler skipped payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.expired",
      2,
      "planning",
      "scheduler expired payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.refreshed",
      3,
      "resource",
      "scheduler refreshed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.rotated",
      4,
      "quality",
      "scheduler rotated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.sealed",
      5,
      "quality",
      "scheduler sealed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.opened",
      0,
      "resource",
      "scheduler opened payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.closed",
      1,
      "consistency",
      "scheduler closed payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.validated",
      2,
      "io",
      "scheduler validated payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.rejected",
      3,
      "io",
      "scheduler rejected payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.throttled",
      4,
      "planning",
      "scheduler throttled payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.promoted",
      5,
      "planning",
      "scheduler promoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.demoted",
      0,
      "planning",
      "scheduler demoted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.merged",
      1,
      "planning",
      "scheduler merged payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.split",
      2,
      "planning",
      "scheduler split payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "payload.evicted",
      3,
      "resource",
      "scheduler evicted payload event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.accepted",
      5,
      "workflow",
      "scheduler accepted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.started",
      0,
      "workflow",
      "scheduler started manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.completed",
      1,
      "io",
      "scheduler completed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.failed",
      2,
      "query",
      "scheduler failed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.retried",
      3,
      "io",
      "scheduler retried manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.skipped",
      4,
      "security",
      "scheduler skipped manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.expired",
      5,
      "planning",
      "scheduler expired manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.refreshed",
      0,
      "resource",
      "scheduler refreshed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.rotated",
      1,
      "quality",
      "scheduler rotated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.sealed",
      2,
      "quality",
      "scheduler sealed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.opened",
      3,
      "resource",
      "scheduler opened manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.closed",
      4,
      "consistency",
      "scheduler closed manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.validated",
      5,
      "io",
      "scheduler validated manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.rejected",
      0,
      "io",
      "scheduler rejected manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.throttled",
      1,
      "planning",
      "scheduler throttled manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.promoted",
      2,
      "planning",
      "scheduler promoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.demoted",
      3,
      "planning",
      "scheduler demoted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.merged",
      4,
      "planning",
      "scheduler merged manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.split",
      5,
      "planning",
      "scheduler split manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "manifest.evicted",
      0,
      "resource",
      "scheduler evicted manifest event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.accepted",
      5,
      "workflow",
      "scheduler accepted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.started",
      0,
      "workflow",
      "scheduler started schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.completed",
      1,
      "io",
      "scheduler completed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.failed",
      2,
      "query",
      "scheduler failed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.retried",
      3,
      "io",
      "scheduler retried schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.skipped",
      4,
      "security",
      "scheduler skipped schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.expired",
      5,
      "planning",
      "scheduler expired schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.refreshed",
      0,
      "resource",
      "scheduler refreshed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.rotated",
      1,
      "quality",
      "scheduler rotated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.sealed",
      2,
      "quality",
      "scheduler sealed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.opened",
      3,
      "resource",
      "scheduler opened schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.closed",
      4,
      "consistency",
      "scheduler closed schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.validated",
      5,
      "io",
      "scheduler validated schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.rejected",
      0,
      "io",
      "scheduler rejected schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.throttled",
      1,
      "planning",
      "scheduler throttled schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.promoted",
      2,
      "planning",
      "scheduler promoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.demoted",
      3,
      "planning",
      "scheduler demoted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.merged",
      4,
      "planning",
      "scheduler merged schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.split",
      5,
      "planning",
      "scheduler split schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "schema.evicted",
      0,
      "resource",
      "scheduler evicted schema event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.accepted",
      2,
      "workflow",
      "scheduler accepted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.started",
      3,
      "workflow",
      "scheduler started session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.completed",
      4,
      "io",
      "scheduler completed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.failed",
      5,
      "query",
      "scheduler failed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.retried",
      0,
      "io",
      "scheduler retried session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.skipped",
      1,
      "security",
      "scheduler skipped session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.expired",
      2,
      "planning",
      "scheduler expired session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.refreshed",
      3,
      "resource",
      "scheduler refreshed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.rotated",
      4,
      "quality",
      "scheduler rotated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.sealed",
      5,
      "quality",
      "scheduler sealed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.opened",
      0,
      "resource",
      "scheduler opened session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.closed",
      1,
      "consistency",
      "scheduler closed session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.validated",
      2,
      "io",
      "scheduler validated session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.rejected",
      3,
      "io",
      "scheduler rejected session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.throttled",
      4,
      "planning",
      "scheduler throttled session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.promoted",
      5,
      "planning",
      "scheduler promoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.demoted",
      0,
      "planning",
      "scheduler demoted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.merged",
      1,
      "planning",
      "scheduler merged session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.split",
      2,
      "planning",
      "scheduler split session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "session.evicted",
      3,
      "resource",
      "scheduler evicted session event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.accepted",
      3,
      "workflow",
      "scheduler accepted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.started",
      4,
      "workflow",
      "scheduler started window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.completed",
      5,
      "io",
      "scheduler completed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.failed",
      0,
      "query",
      "scheduler failed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.retried",
      1,
      "io",
      "scheduler retried window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.skipped",
      2,
      "security",
      "scheduler skipped window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.expired",
      3,
      "planning",
      "scheduler expired window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.refreshed",
      4,
      "resource",
      "scheduler refreshed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.rotated",
      5,
      "quality",
      "scheduler rotated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.sealed",
      0,
      "quality",
      "scheduler sealed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.opened",
      1,
      "resource",
      "scheduler opened window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.closed",
      2,
      "consistency",
      "scheduler closed window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.validated",
      3,
      "io",
      "scheduler validated window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.rejected",
      4,
      "io",
      "scheduler rejected window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.throttled",
      5,
      "planning",
      "scheduler throttled window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.promoted",
      0,
      "planning",
      "scheduler promoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.demoted",
      1,
      "planning",
      "scheduler demoted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.merged",
      2,
      "planning",
      "scheduler merged window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.split",
      3,
      "planning",
      "scheduler split window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "window.evicted",
      4,
      "resource",
      "scheduler evicted window event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.accepted",
      4,
      "workflow",
      "scheduler accepted index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.started",
      5,
      "workflow",
      "scheduler started index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.completed",
      0,
      "io",
      "scheduler completed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.failed",
      1,
      "query",
      "scheduler failed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.retried",
      2,
      "io",
      "scheduler retried index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.skipped",
      3,
      "security",
      "scheduler skipped index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.expired",
      4,
      "planning",
      "scheduler expired index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.refreshed",
      5,
      "resource",
      "scheduler refreshed index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.rotated",
      0,
      "quality",
      "scheduler rotated index event used by offline trace review and triage workflows"
    },
    CatalogEntry{
      "scheduler",
      "index.sealed",
      1,
      "quality",
      "scheduler sealed index event used by offline trace review and triage workflows"
    },
  };
  return entries;
}
}
const std::vector<CatalogEntry>& BuiltinCatalog() {
  return Entries();
}
std::vector<CatalogEntry> CatalogByService(const std::string& service) {
  std::vector<CatalogEntry> out;
  for (const auto& entry : Entries()) {
    if (entry.service == service) {
      out.push_back(entry);
    }
  }
  return out;
}
std::vector<CatalogEntry> SearchCatalog(const std::string& needle) {
  std::vector<CatalogEntry> out;
  std::string q = Lower(needle);
  for (const auto& entry : Entries()) {
    std::string hay = Lower(entry.service + " " + entry.event + " " + entry.category + " " + entry.description);
    if (hay.find(q) != std::string::npos) {
      out.push_back(entry);
    }
  }
  return out;
}
std::string ClassifyRecord(const EventRecord& record) {
  for (const auto& entry : Entries()) {
    if (entry.service == record.service && entry.event == record.name) {
      return entry.category;
    }
  }
  if (record.level >= 4) {
    return "error";
  }
  if (record.payload.size() > 4096) {
    return "payload";
  }
  return "uncategorized";
}
std::string CatalogSummary() {
  std::ostringstream os;
  os << "entries=" << Entries().size();
  std::vector<std::string> services;
  for (const auto& entry : Entries()) {
    if (std::find(services.begin(), services.end(), entry.service) == services.end()) {
      services.push_back(entry.service);
    }
  }
  os << " services=" << services.size();
  return os.str();
}
}
