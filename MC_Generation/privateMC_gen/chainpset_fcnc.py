from metis.CMSSWTask import CMSSWTask
from metis.Sample import DirectorySample, DummySample
from metis.Path import Path
from metis.StatsParser import StatsParser
import time

from allconfig import *

def runall(special_dir, tag, total_nevents, events_per_output, config):

 for _ in range(25):

    proc_tag = "v1"
    #special_dir = "workflowtest/ProjectMetis"
    #special_dir = "miniaod_runII/JHUSample_ttH"

    cmssw_v_gensim = config["cmssw_v_gensim"] 
    pset_gensim = config["pset_gensim"]
    scram_arch_gensim = config["scram_arch_gensim"]

    cmssw_v_aodsim = config["cmssw_v_aodsim"]
    pset_aodsim = config["pset_aodsim"]
    scram_arch_aodsim = config["scram_arch_aodsim"]

    pset_aodsim2 = config["pset_aodsim2"]
    cmssw_v_aodsim2 = cmssw_v_aodsim #config["pset_aodsim2"]
    scram_arch_aodsim2 = scram_arch_aodsim #config["scram_arch_aodsim2"]

    cmssw_v_miniaodsim = config["cmssw_v_miniaodsim"]
    pset_miniaodsim = config["pset_miniaodsim"]
    scram_arch_miniaodsim = config["scram_arch_miniaodsim"]

    step1 = CMSSWTask(
            # Change dataset to something more meaningful (but keep STEP1, as we use this 
            # for string replacement later); keep N=1
            sample = DummySample(N=1, dataset="/"+ tag+ "_STEP1"),
            # A unique identifier
            tag = proc_tag,
            special_dir = special_dir,
            # Probably want to beef up the below two numbers to control splitting,
            # but note that step2 is the bottleneck, so don't put too many events
            # in one output file here
            events_per_output = events_per_output,
            total_nevents = total_nevents,
            #events_per_output = 50,
            #total_nevents = 1000,
            # We have one input dummy file, so this must be True
            split_within_files = True,
            pset = "psets/" + pset_gensim,
            cmssw_version = cmssw_v_gensim,
            scram_arch = scram_arch_gensim,
            )

    step2 = CMSSWTask(
            sample = DirectorySample(
                location = step1.get_outputdir(),
                dataset = step1.get_sample().get_datasetname().replace("STEP1","STEP2"),
                ),
            tag = proc_tag,
            special_dir = special_dir,
            open_dataset = True,
            files_per_output = 1,
            pset = "psets/" + pset_aodsim,
            cmssw_version = cmssw_v_aodsim,
            scram_arch = scram_arch_aodsim,
            )

    step3 = CMSSWTask(
            sample = DirectorySample(
                location = step2.get_outputdir(),
                dataset = step2.get_sample().get_datasetname().replace("STEP2","STEP3"),
                ),
            tag = proc_tag,
            special_dir = special_dir,
            open_dataset = True,
            files_per_output = 1,
            pset = "psets/" + pset_aodsim2,
            cmssw_version = cmssw_v_aodsim2,
            scram_arch = scram_arch_aodsim2,
            )

    step4 = CMSSWTask(
            sample = DirectorySample(
                location = step3.get_outputdir(),
                dataset = step3.get_sample().get_datasetname().replace("STEP3","STEP4"),
                ),
            tag = proc_tag,
            special_dir = special_dir,
            open_dataset = True,
            files_per_output = 1,
            output_name = "step4.root",
            pset = "psets/" + pset_miniaodsim,
            cmssw_version = cmssw_v_miniaodsim,
            scram_arch = scram_arch_miniaodsim,
            # condor_submit_params = {"sites":"UAF,UCSD"},
            )
    '''
    step5 = CMSSWTask(
            sample = DirectorySample(
                location = step4.get_outputdir(),
                dataset = step4.get_sample().get_datasetname().replace("STEP4","STEP5"),
                ),
            tag = proc_tag,
            special_dir = special_dir,
            open_dataset = True,
            files_per_output = 1,
            pset = "psets/TOP-RunIIFall17NanoAODv7-00001_1_cfg.py",
            # The below two lines should match output file names in the pset
            output_name = "step5.root",
            #other_outputs = ["step3_inMINIAODSIM.root","step3_inDQM.root"],
            cmssw_version = "CMSSW_10_2_22",
            scram_arch = "slc6_amd64_gcc700",
            # condor_submit_params = {"sites":"UAF,UCSD"},
            )
    '''
    #for _ in range(25):
    total_summary = {}
    for task in [step1,step2,step3,step4]:
        task.process()
        summary = task.get_task_summary()
        total_summary[task.get_sample().get_datasetname()] = summary
    StatsParser(data=total_summary, webdir="~/public_html/dump/metis/").do()
    time.sleep(600)

runall("miniaod_runII", "ST_HAD_HUT_2016_20200522_v1", 1000000, 200, st_had_hut_2016)
runall("miniaod_runII", "ST_HAD_HCT_2016_20200522_v1", 1000000, 200, st_had_hct_2016)
runall("miniaod_runII", "TT_T2HJ_HAD_HUT_2018_20200522_v1", 1000000, 200, tt_t2HJ_had_hut_2018)
#runall("miniaod_runII", "TT_T2HJ_HAD_HCT_2018_20200522_v1", 1000000, 200, tt_t2HJ_had_hct_2018)
#runall("miniaod_runII", "TT_aT2HJ_HAD_HUT_2018_20200522_v1", 1000000, 200, tt_at2HJ_had_hut_2018)
#runall("miniaod_runII", "TT_aT2HJ_HAD_HCT_2018_20200522_v1", 1000000, 200, tt_at2HJ_had_hct_2018)



