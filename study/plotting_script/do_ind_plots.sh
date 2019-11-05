
python make_ind_plot_mutauh.py -cat gen_org -lY -name Higgs_pt -ch mutau 
python make_ind_plot_mutauh.py -cat gen -lY -name Higgs_pt -ch mutau
python make_ind_plot_mutauh.py -cat gen -name mu_pt -ch mutau
python make_ind_plot_mutauh.py -cat gen -name mu_phi -ch mutau
python make_ind_plot_mutauh.py -cat gen -name mu_eta -ch mutau
python make_ind_plot_mutauh.py -cat gen -name tau_pt -ch mutau
python make_ind_plot_mutauh.py -cat gen -name tau_phi -ch mutau
python make_ind_plot_mutauh.py -cat gen -name tau_eta -ch mutau

cp plot_* /afs/hep.wisc.edu/home/ms/public_html/boosted_study/study_1/

echo "*************** plots made ***************"
