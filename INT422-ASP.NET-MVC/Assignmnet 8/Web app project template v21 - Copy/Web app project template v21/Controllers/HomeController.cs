using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class HomeController : Controller
    {
        // Reference to the manager object
        Manager m = new Manager();

        public ActionResult Index()
        {
            return View();
        }
    }
}