void DFS(vector<vector<int> > &module_out_sigs, vector<long> &start_counts,
        unordered_map<int, vector<int> > &sig_start_module, int current_module)
{
    start_counts[current_module]++;
    for (int sig : module_out_sigs[current_module]) {
        if (sig_start_module.find(sig) != sig_start_module.end()) {
            for (int module : sig_start_module[sig]) {
                DFS(module_out_sigs, start_counts, sig_start_module, module);
            }
        }
    }
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d%d", &N, &M);
        int init_sig[M];
        for (int j = 0; j < M; j++) {
            scanf("%d", init_sig+j);
        }
        unordered_map<int, vector<int> > sig_start_module;
        vector<vector<int> > module_out_sigs;
        for (int j = 0; j < N; j++) {
            int sig_start;
            int num_out_sig;
            scanf("%d%d", &sig_start, &num_out_sig);
            if (sig_start_module.find(sig_start) != sig_start_module.end()) {
                sig_start_module[sig_start].push_back(j);
            }
            else{
                sig_start_module[sig_start] = vector<int>(1, j);
            }
            vector<int> out_sigs(num_out_sig, 0);
            for (int k = 0; k < num_out_sig; k++) {
                int tmp = 0;
                scanf("%d", &tmp);
                out_sigs[k] = tmp;
            }
            module_out_sigs.push_back(out_sigs);
        }

        vector<long> start_counts(N, 0);

        for (int j = 0; j < M; j++) {
            int s = init_sig[j];
            if (sig_start_module.find(s) != sig_start_module.end()) {
                for (int module : sig_start_module[s]) {
                    DFS(module_out_sigs, start_counts, sig_start_module, module);
                }
            }
        }

        for (int j = 0; j < N - 1; j++) {
            cout << (start_counts[j]%142857) << " ";
        }

        cout << (start_counts[N-1]%142857) << endl;
    }
}
