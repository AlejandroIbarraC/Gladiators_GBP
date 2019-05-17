package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Gladiators;
import tec.ac.cr.gladiators.logic.Holder;
import tec.ac.cr.gladiators.logic.facade.GladiatorsFacade;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;

@Path("populations/gladiators")
public class GladiatorsServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Gladiators> generateGladiators(){
        System.out.println(1);
        if (Holder.gladiatorsArrayList == null){
            Holder.gladiatorsArrayList = GladiatorsFacade.initPopulation();
        }
        return Holder.gladiatorsArrayList;
    }

    @POST
    @Path("stats")
    public void getGladiators(){
        System.out.println(2);
        Holder.gladiatorsArrayList = GladiatorsFacade.updatePopulation();
    }

}
