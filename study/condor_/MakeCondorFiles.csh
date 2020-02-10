#!/bin/sh


#export CMSSW_RELEASE_BASE=/cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_1/
export CMSSW_RELEASE_BASE=/cvmfs/cms.cern.ch/slc7_amd64_gcc630/cms/cmssw/CMSSW_9_4_13/
cat> Job_${3}.sh<<EOF
#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh 
cd $CMSSW_RELEASE_BASE
eval `scramv1 runtime -sh`
cd \${_CONDOR_SCRATCH_DIR}
EOF
cat Submit_GluGluHToTauTau_mt_${4}.sh >> Job_${3}.sh
chmod 775 Job_${3}.sh
#mkdir -p /nfs_scratch/jmadhusu/CMSSW_9_4_13/src/monoH/Out_${3}
cat>condor_${3}<<EOF
x509userproxy = /tmp/x509up_u4548
universe = vanilla
Executable = Job_${3}.sh
Notification         = never
WhenToTransferOutput = On_Exit
ShouldTransferFiles  = yes
Requirements = (TARGET.UidDomain == "hep.wisc.edu" && TARGET.HAS_CMS_HDFS && OpSysAndVer == "CENTOS7" && TARGET.Arch == "X86_64" && (MY.RequiresSharedFS=!=true || TARGET.HasAFS_OSG) && (TARGET.OSG_major =!= undefined || TARGET.IS_GLIDEIN=?=true) && IsSlowSlot=!=true)
on_exit_remove       = (ExitBySignal == FALSE && (ExitCode == 0 || ExitCode == 42 || NumJobStarts>3))
+IsFastQueueJob      = True
getenv               = True
request_memory       = 1992
request_disk         = 2048000

#OutputDestination = /nfs_scratch/jmadhusu/CMSSW_9_4_13/src/monoH/Out_${3}
#Initialdir = Out_${3}         
Transfer_Input_Files = /nfs_scratch/jmadhusu/CMSSW_10_2_10/src/boosted_H/${1}, /nfs_scratch/jmadhusu/CMSSW_10_2_10/src/boosted_H/

output               = \$(Cluster)_\$(Process)_${3}.out
error                = \$(Cluster)_\$(Process)_${3}.err
Log                  = \$(Cluster)_\$(Process)_${3}.log
Queue
EOF

condor_submit condor_${3}
