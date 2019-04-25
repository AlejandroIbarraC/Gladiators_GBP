package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Generator;
import tec.ac.cr.gladiators.logic.Gladiators;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;

@Path("populations/gladiators")
public class GladiatorsServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Gladiators> generateGladiators(){
        System.out.println(1);
        return Generator.generateGladiators(10);
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getGladiators(ArrayList<Gladiators> gladiatorsArrayList){
        System.out.println(2);
    }

}
