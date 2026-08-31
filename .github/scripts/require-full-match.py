#!/usr/bin/env python3
"""Require a 100% reccmp match on the ReproBit outcome.

Reads <TARGET>PROGRESS.json for every target given on the command line and
fails unless every row scores 1.0 and every annotated function was compared.
"""
import json
import sys

failed = False
for target in sys.argv[1:]:
    with open(f"{target}PROGRESS.json", encoding="utf-8") as handle:
        report = json.load(handle)
    offending = []
    for entity in report["data"]:
        matching = entity.get("matching")
        if not isinstance(matching, (int, float)) or matching < 1.0:
            offending.append(entity)
    functions = sum(1 for e in report["data"] if e.get("type") == 1)
    annotated = report["function_count"]
    print(
        f"{target}: {len(report['data'])} rows,"
        f" {len(offending)} below 100%,"
        f" {functions} of {annotated} annotated functions compared"
    )
    for entity in offending:
        failed = True
        name = entity.get("name", "?")
        print(f"  {entity.get('address')}  {entity.get('matching')}  {name}")
    if functions != annotated:
        failed = True
        print(f"  {annotated - functions} annotated function(s) missing from the comparison")
if failed:
    sys.exit(
        "reccmp did not score every row at 100%."
        " The ReproBit comparison build must match retail exactly."
    )
