using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21.Controllers
{
    public class GenreController : Controller
    {
        private Manager m = new Manager();

        [AllowAnonymous]
        // GET: Genre
        public ActionResult Index()
        {
            return View(m.GenreGetAll());
        }
    }
}
