

void testcase(){
  // a,b,memo,bs function initi
// Forwarding references
	auto dp = [&](auto&& self,int ia,int ib)->ll{
		if (ia > n){
		return 0;
		}
		if (ib > m){
			return INF;
		}
		ll& ret = memo[ia][ib];
		if (ret!=-1) return ret;
		// dbg(ia,ib);
		int idx = bs(ia,ib);
		ll ch1 = INF, ch2=INF;
		if (idx!=-1){
			ch1 = (m-ib)+self(self,idx+1,ib);
		}
		ch2 = self(self,ia,ib+1);
		return ret = min(ch1,ch2);
	};
	ll ans = dp(dp,1,1);
}
