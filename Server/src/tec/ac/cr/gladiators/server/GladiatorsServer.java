package tec.ac.cr.gladiators.server;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;

@Path("populations/gladiators")
public class GladiatorsServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public int generateGladiators(){
        return 1;
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getGladiators(){
        System.out.println("Hola");
    }

}
