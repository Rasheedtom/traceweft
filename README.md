# TraceWeft

TraceWeft is an offline trace log utility for teams that collect application events from batch jobs, local services, and embedded gateways. It stores event records in a compact `.twft` container and provides tools to inspect, verify, query, compact, classify, and export those traces without a database server. TraceWeft also ships with a built-in event catalog for common batch, gateway, storage, queue, and worker events so local triage reports can label records consistently even when a central observability service is unavailable.

The command line program is `twft`.

```bash
twft inspect sample.twft
twft verify sample.twft
twft stats sample.twft
twft query sample.twft 'level >= 3 and service = "worker"'
twft export-json sample.twft out.json
twft timeline sample.twft 60000
twft catalog worker
twft compact input.twft compacted.twft
```

## Repository layout

- `include/traceweft/` public C++ headers
- `src/` implementation
- `tools/` command line tool
- `tests/` unit and integration tests
- `examples/` small trace samples and scripts
- `fuzz/` parser harnesses used during development and CI security testing

## Format overview

A `.twft` file starts with a fixed header, followed by a schema block, a segment table, and one or more event segments. Segments contain typed records with timestamps, stream identifiers, severity levels, attributes, and optional compressed payloads. The reader is designed to survive partial files and provide useful diagnostics for repair workflows.

## Build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## License

MIT.

TraceWeft stores event payloads with one of four codecs: raw bytes, run-length encoding, XOR-delta streams, or PackBits-style literals. RLE payloads use short runs for compact telemetry and may include extended runs emitted by older collectors for repeated status bytes.
