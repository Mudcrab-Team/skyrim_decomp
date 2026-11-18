"""Advisory selection and scoped renewals, using synthetic metadata and no network."""
from datetime import datetime, timedelta, timezone
from pathlib import Path
import sys
import unittest
from unittest.mock import Mock

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import claims


class AdvisoryClaims(unittest.TestCase):
    def test_mixed_batch_renewal_does_not_refresh_untouched_rva(self):
        now = datetime.now(timezone.utc)
        old = (now - timedelta(hours=25)).isoformat()
        issue = dict(number=1, entries=[(0x1000, 0x3000)], updated_at=old)
        gh = Mock()
        self.assertTrue(claims.renew(gh, issue, [(0x1000, 0x1001)]))
        text = gh.comment.call_args.args[1]
        raw = dict(number=1, title='claim: synthetic batch', body='```text\nskyrim-claim-v1 synthetic\n0x1000-0x3000\n```',
                   updated_at=now.isoformat())
        events = [dict(body=text, created_at=now.isoformat())]
        raw['updated_at'] = claims.activity(lambda _: events, 'x/y', raw)
        index = claims.ClaimIndex([claims.parse_issue(raw)])
        self.assertTrue(claims.claimed(index, 0x1000))
        self.assertFalse(claims.claimed(index, 0x2000))
        self.assertFalse(index.overlaps([(0x2000, 0x2001)]))
        self.assertTrue(index.overlaps([(0x1000, 0x1001)]))
        self.assertFalse(claims.live_entries(index.records[0], now + timedelta(hours=24)))

    def test_renewal_before_lapse_preserves_remaining_original_24_hours(self):
        now = datetime.now(timezone.utc)
        issue = dict(entries=[(1, 3)], updated_at=now.isoformat(),
                     claim_base_updated_at=(now - timedelta(hours=13)).isoformat(),
                     claim_renewals=[dict(time=now.isoformat(), entries=[(1, 2)])])
        self.assertEqual(claims.live_entries(issue, now + timedelta(hours=10)), [(1, 3)])
        self.assertEqual(claims.live_entries(issue, now + timedelta(hours=11)), [(1, 2)])

    def test_inactive_batch_never_renews(self):
        gh = Mock()
        issue = dict(number=1, entries=[(1, 2)], updated_at=datetime.now(timezone.utc).isoformat())
        self.assertFalse(claims.renew(gh, issue, []))
        gh.comment.assert_not_called()

    def test_inactive_scope_maintenance_preserves_original_expiry(self):
        now = datetime.now(timezone.utc)
        old = (now - timedelta(hours=25)).isoformat()
        issue = dict(number=1, entries=[(0x1000, 0x1001)], updated_at=old)
        gh = Mock()
        self.assertTrue(claims.renew(gh, issue, [], 'Scope maintenance.', maintenance=True))
        raw = dict(number=1, title='claim: synthetic batch',
                   body='```text\nskyrim-claim-v1 synthetic\n0x1000\n```', updated_at=now.isoformat())
        raw['updated_at'] = claims.activity(lambda _: [dict(body=gh.comment.call_args.args[1], created_at=now.isoformat())], 'x/y', raw)
        self.assertEqual(claims.live_entries(claims.parse_issue(raw), now), [])


if __name__ == '__main__':
    unittest.main()
