package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Holder;
import tec.ac.cr.gladiators.logic.Towers;
import tec.ac.cr.gladiators.logic.facade.TowersFacade;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;

@Path("populations/towers")
public class TowersServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Towers> generateTowers(){
        System.out.println(3);
        if (Holder.towersArrayList == null){
            Holder.towersArrayList = TowersFacade.initPopulation();
        }
        return Holder.towersArrayList;
    }

    @POST
    @Path("stats")
    public void getTowers(){
        System.out.println(4);
        Holder.towersArrayList = TowersFacade.updatePopulation();
    }

}
