package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Holder;
import tec.ac.cr.gladiators.logic.facade.GladiatorsFacade;
import tec.ac.cr.gladiators.logic.facade.TowersFacade;

import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;

@Path("populations")
public class Populations {

    @POST
    public void initialize(){
        System.out.println(5);
        Holder.gladiatorsArrayList = null;
        Holder.towersArrayList = null;
    }

    @POST
    @Path("skip")
    @Consumes(MediaType.APPLICATION_JSON)
    public void skipGenerations(int num){
        System.out.println(6);
        GladiatorsFacade.skipGenerations(num);
        TowersFacade.skipGenerations(num);
    }

}
